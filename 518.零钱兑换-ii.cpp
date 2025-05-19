/*
 * @lc app=leetcode.cn id=518 lang=cpp
 *
 * [518] 零钱兑换 II
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1));
        // 直接 dp 会溢出，所以先检查一下是否有可能的组合
        vector<vector<bool>> valid(coins.size() + 1, vector<bool>(amount + 1));
        for (int i = 1; i <= coins.size(); i++) {
            valid[i][0] = true;
            for (int j = 1; j <= amount; j++) {
                valid[i][j] = valid[i - 1][j];
                if (j >= coins[i - 1]) {
                    valid[i][j] = valid[i][j] || valid[i][j - coins[i - 1]];
                }
            }
        }
        if (!valid[coins.size()][amount]) {
            return 0;
        }


        // dp[i][j] 表示最多使用到 coin[i - 1] 时兑换 j 的组合数
        // dp[i][j] = dp[i - 1][j] + dp[i][j - coin[i - 1]]
        // dp[..][0] = 1 dp[0][..] = 0
        for (int i = 1; i <= coins.size(); i++) {
            dp[i][0] = 1;
            for (int j = 1; j <= amount; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j >= coins[i - 1]) {
                    dp[i][j] += dp[i][j - coins[i - 1]];
                }
            }
        }

        return dp[coins.size()][amount];

        // 可以进一步压缩状体啊
    }
};
// @lc code=end

