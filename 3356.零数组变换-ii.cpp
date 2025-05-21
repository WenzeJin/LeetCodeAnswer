/*
 * @lc app=leetcode.cn id=3356 lang=cpp
 *
 * [3356] 零数组变换 II
 */

#include <climits>
#include <vector>

using namespace std;

// @lc code=start


class Solution {
public:
    // 计算 num 在使用 [0, end] 的 queries 时是否能被减为 0;
    bool minZeroArray(vector<int>& nums, vector<vector<int>>& queries, int end) {
        // 利用差分数组和前缀和，计算每个位置最多能减少多少，然后和原先比对，时间 O(n)
        //cout << "end: " << end << endl;
        vector<int> cover(nums.size() + 1);

        for (int i = 0; i <= end; i++) {
            cover[queries[i][0]] += queries[i][2];
            cover[queries[i][1] + 1] -= queries[i][2];
        }

        int sum = 0;
        for (auto& x: cover) {
            sum += x;
            x = sum;
        }
        
        for(int i = 0; i < nums.size(); i++) {
            if (cover[i] < nums[i]) {
                //cout << "false" << endl;
                return false;
            }
        }

        //cout << "true" << endl;
        return true;
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        // 在 [0, n - 1] 间二分搜索 k
        int lo = -1, hi = queries.size() - 1;
        int res = INT_MAX;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (minZeroArray(nums, queries, mid)) {
                res = mid + 1;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return res == INT_MAX ? -1 : res;

        // 还可以用另一个思路，既然是单调的，我们先从最少的开始，当某一位不能变成0了，再不断移入queries，直到当前位满足要求，遍历每一位的过程和求前缀和同步进行
    }
};
// @lc code=end

