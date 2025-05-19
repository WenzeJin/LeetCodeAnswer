/*
 * @lc app=leetcode.cn id=312 lang=cpp
 *
 * [312] 戳气球
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 2, vector<int>(n + 2));
        // dp[i][j] means max score after breaking all the balloons in (i, j), (without i and j) finally we want dp[0][i + 1];

        // for (int i = 0; i < n + 2; i++) {
        //     dp[i][i] = 0;
        // }

        // fake nums[0] is 1 fake nums[n + 1] is 1, nums[k] is nums[k - 1]

        // dp[i][j] = max(dp[i][k] + dp[k][j] + nums[k] * nums[i] * nums[j] for k in (i, j))
        for (int i = n; i >= 0; i--) {
            for (int j = i + 1; j < n + 2; j++) {
                int num_i = i == 0 ? 1 : nums[i - 1];
                int num_j = j == n + 1 ? 1 : nums[j - 1];
                for (int k = i + 1; k < j; k++) {
                    // 最后一个戳破的是 k
                    // k < j 所以我们已经算过， k > i 所以我们已经算过
                    dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + nums[k - 1] * num_i * num_j);
                }
            }
        }

        return dp[0][n + 1];
    }
};
// @lc code=end

