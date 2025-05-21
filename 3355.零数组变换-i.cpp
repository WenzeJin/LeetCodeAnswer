/*
 * @lc app=leetcode.cn id=3355 lang=cpp
 *
 * [3355] 零数组变换 I
 */

// @lc code=start

#include <vector>


using namespace std;

class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        // 实际上就是一个覆盖问题，如果一个位置的覆盖次数大于他自己的大小，那么就可以变成 0
        // 首先的想法是用一张表记录每个位置的覆盖次数，但是这样复杂度太高，对于一个 [i, j] 的 query，我们需要每一个位置都遍历一遍
        // 就可以考虑先排序，先按 i，再按 j 排序，然后我们同时遍历每个位置和query，如果当前query可以开始从这个位置覆盖，我们加入窗口中，前进时，需要pop不再覆盖的query，那么此时就需要按 j 排序，所以这应该是一个优先队列。

        // sort(queries.begin(), queries.end(), [](vector<int>& x, vector<int>& y) -> bool {
        //     if (x[0] < y[0]) {
        //         return true;
        //     } else if (x[0] == y[0]) {
        //         return x[1] < y[1];
        //     }
        //     return false;
        // });

        // priority_queue<int, vector<int>, std::greater<int>> pq;

        // auto qiter = queries.begin();

        // for(int i = 0; i < nums.size(); i++) {
        //     // pop
        //     while (!pq.empty() && pq.top() < i) {
        //         pq.pop();
        //     }

        //     // push
        //     while (qiter != queries.end() && (*qiter)[0] == i) {
        //         pq.push((*qiter)[1]);
        //         qiter++;
        //     }

        //     if (pq.size() < nums[i]) {
        //         return false;
        //     }
        // }

        // return true;

        // 这一题可以使用差分数组，用一个数组记录每一个位置上的增量和减量，然后用前缀和记录到目前为止的和，即覆盖数量，最后比较就可以了，时间从 nlogn 优化到 n

        vector<int> delta(nums.size() + 1);
        for (auto& query: queries) {
            delta[query[0]] += 1;
            delta[query[1] + 1] -= 1;
        }

        int sum = 0;
        for (auto& x: delta) {
            sum += x;
            x = sum;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > delta[i]) {
                return false;
            }
        }

        return true;
    }
};
// @lc code=end

