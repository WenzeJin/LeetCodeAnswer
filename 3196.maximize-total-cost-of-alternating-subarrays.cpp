/*
 * @lc app=leetcode.cn id=3196 lang=cpp
 *
 * [3196] Maximize Total Cost of Alternating Subarrays
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    long long maximumTotalCost(vector<int>& nums) {
        // dp[i] 表示到 nums[i - 1] 为止的最大化总成本
        int n = nums.size();
        vector<int> dp(n + 1);
        dp[0] = nums[0];

        for (int i = 0; i < n; i++) {
            int sub = nums[i];
            dp[i + 1] = dp[i] + sub;
            if (i > 0) {
                sub = (long long)nums[i - 1] - sub;
            }
            dp[i + 1] = max(dp[i + 1], dp[i - 1] + sub);
            
            // 枚举划分点
            // for (int j = i - 1; j >= 0; j--) {
            //     sub = nums[j] - sub;
            //     dp[i + 1] = max(dp[i + 1], dp[j] + sub);
            // }
        }
        return dp[n];
    }
};
// @lc code=end

