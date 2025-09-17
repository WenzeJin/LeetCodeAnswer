/*
 * @lc app=leetcode.cn id=1911 lang=cpp
 *
 * [1911] Maximum Alternating Subsequence Sum
 */

#include <climits>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        // 分两个状态，已选为偶数和基数
        int n = nums.size();
        vector<vector<long long>> dp(n + 1, vector<long long>(2));
        dp[0][0] = 0; dp[0][1] = LLONG_MIN / 2;
        for (int i = 1; i <= n; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - nums[i - 1]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + nums[i - 1]);
        }
        return max(dp[n][0], dp[n][1]);
    }
};
// @lc code=end

