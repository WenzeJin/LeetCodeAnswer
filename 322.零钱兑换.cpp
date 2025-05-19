/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, INT_MAX));
        dp[0][0] = 0;
        for (int a = 1; a <= amount; a++) {
            dp[0][a] = INT_MAX; // impossible
        }
        for (int i = 1; i <= coins.size(); i++) {
            dp[i][0] = 0;
            for (int j = 1; j <= amount; j++) {
                if (j >= coins[i - 1]) {
                    if (dp[i][j - coins[i - 1]] != INT_MAX) {
                        dp[i][j] = min(dp[i - 1][j], dp[i][j - coins[i - 1]] + 1);
                    } else {
                        dp[i][j] = dp[i - 1][j];
                    }
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        int n = coins.size();
        return dp[n][amount] == INT_MAX ? -1 : dp[n][amount];
        // 可以进一步状态压缩优化。
    }
};
// @lc code=end

