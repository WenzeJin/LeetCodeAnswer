/*
 * @lc app=leetcode.cn id=2585 lang=cpp
 *
 * [2585] Number of Ways to Earn Points
 */

#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
#define MOD 1000000007

class Solution {
public:
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        // dp[i][j][k] 表示使用前 i 种题目完成 k 分数，其中 第 i 种题目至多使用 j 次的（j > count_i 则认为是 count_i）方案数，i 可以压缩。

        int n = types.size();
        int m = 0;
        for (auto& type: types) {
            m = max(m, type[0]);
        }
        int t = target;

        vector<vector<int>> dp_prev(m + 1, vector<int>(t + 1));
        vector<vector<int>> dp(m + 1, vector<int>(t + 1));

        for (int j = 0; j <= m; j++) {
            dp[j][0] = 1; // 不选择
        }

        for (int i = 0; i < n; i++) {
            swap(dp, dp_prev);
            for (int j = 0; j <= types[i][0]; j++) {
                dp[j][0] = 1;
                for (int k = 1; k <= t; k++) {
                    dp[j][k] = 0;
                    if (j > 0 && k >= types[i][1]) {
                        // 使用一个
                        dp[j][k] += dp[j - 1][k - types[i][1]];
                        dp[j][k] %= MOD;
                    }
                    if (i > 0) {
                        // 不使用
                        dp[j][k] += dp_prev[types[i - 1][0]][k];
                        dp[j][k] %= MOD;
                    }
                }
            }
        }

        return dp[types[n - 1][0]][target];
    }
};
// @lc code=end

