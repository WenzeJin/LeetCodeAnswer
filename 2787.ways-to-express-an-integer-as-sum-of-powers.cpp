/*
 * @lc app=leetcode.cn id=2787 lang=cpp
 *
 * [2787] Ways to Express an Integer as Sum of Powers
 */

#include <cmath>
#include <vector>



using namespace std;

// @lc code=start
#define MOD 1000000007
class Solution {
public:
    int numberOfWays(int n, int x) {
        // 0 - 1 背包问题，每一位选或不选
        // 不选：dp[i - 1][j]
        // 选：dp[i - 1][j - i ^ n]
        int nn = pow(n, 1.0 / x) + 2;
        int mm = n + 1;

        vector<int> pre_calc(nn);
        for (int i = 0; i < pre_calc.size(); i++) {
            pre_calc[i] = pow(i, x);
        }

        vector<vector<int>> dp(nn, vector<int>(mm));

        for (int i = 0; i < nn; i++) {
            dp[i][0] = 1;
        }

        for (int i = 1; i < nn; i++) {
            for (int j = 1; j < mm; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j >= pre_calc[i]) {
                    dp[i][j] += dp[i - 1][j - pre_calc[i]];
                    dp[i][j] %= MOD;
                }
            }
        }

        return dp[nn - 1][mm - 1];
    }
};
// @lc code=end

