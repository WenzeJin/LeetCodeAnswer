/*
 * @lc app=leetcode.cn id=3362 lang=cpp
 *
 * [3362] 零数组变换 III
 */

#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        // 我们可以用一个贪心的思想，先开始遍历 nums，并用一个差分数组记录已经选中的 queries，前缀和即目前为止最多可以消去的数字，如果此时已经选中的 queries 不够当前位置去消除了，那么就要选新的 queries，选择的方法是贪心选覆盖最多的 query
        // 为什么这里贪心是对的？因为可以这么想，假设有一个方案，它这一步不选覆盖最多的 query，且是最优的，那么我们选覆盖最多的query，是不是总选择数一定少于它？因为我们的第一段覆盖最多，肯定能 cover 这个所谓最优方案的第一段，说不定还能 cover 更多

        vector<int> delta(nums.size() + 1);
        priority_queue<int> pq; // pq 只保存 pq 中 queries 的结束位置。当一个 queries 的起始位置小于等于当前位置时，才能加入 pq，因为此时它才是可选的

        // 首先要对 queries 进行排序
        sort(queries.begin(), queries.end(), [](vector<int>& a, vector<int>& b) -> bool {
            return a[0] < b[0];
        });


        int prefix = 0;
        int qp = 0;
        int selected = 0;
        for (int i = 0; i < nums.size(); i++) {
            prefix += delta[i];
            while (qp < queries.size() && queries[qp][0] <= i) {
                pq.push(queries[qp][1]);
                ++qp;
            }

            while (prefix < nums[i]) {
                // we need new query
                // 这里需要注意，pq 顶上的最大覆盖如果也不够了，那么就无法再选择了。
                if (pq.empty() || pq.top() < i) {
                    return -1;
                }
                --delta[pq.top() + 1];
                ++prefix;
                ++selected;
                pq.pop();
            }
        }
        return queries.size() - selected;
    }
};
// @lc code=end

