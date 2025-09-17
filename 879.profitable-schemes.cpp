/*
 * @lc app=leetcode.cn id=879 lang=cpp
 *
 * [879] Profitable Schemes
 */

#include <cstddef>
#include <vector>

using namespace std;

// @lc code=start
#define MOD 1000000007

class Solution {
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        
        int jobs = profit.size();

        typedef vector<vector<int>> Buffer;

        // dp[i][j][k] 代表 利用前 i 个任务在 j 人数下达到 k 利润的方案数，i 压缩。 0 - 1 背包问题

        Buffer dp_prev(n + 1, vector<int>(minProfit + 1));
        Buffer dp(n + 1, vector<int>(minProfit + 1));

        // 初始化 dp_prev，为 0 任务下, 用任何人数达到 0 利润是可行的
        for (int j = 0; j <= n; j++) {
            dp_prev[j][0] = 1;
        }

        

        // 不断迭代
        for (int i = 1; i <= jobs; i++) {
            // 在 i 任务下，用任何人数达到 0 利润是可行的
            for (int j = 0; j <= n; j++) {
                dp[j][0] = dp_prev[j][0];   // 剩下的人不安排任何此工作
                if (j >= group[i - 1]) {
                    dp[j][0] += dp_prev[j - group[i - 1]][0];   // 或安排无意义的工作
                }
            }
            
            for (int k = 1; k <= minProfit; k++) {
                // j = 0 不可能，默认0
                for (int j = 1; j <= n; j++) {
                    dp[j][k] = dp_prev[j][k];
                    if (j >= group[i - 1]) {
                        if (k >= profit[i - 1]) {
                            dp[j][k] += dp_prev[j - group[i - 1]][k - profit[i - 1]];
                        } else {
                            dp[j][k] += dp_prev[j - group[i - 1]][0];
                        }
                    }
                    dp[j][k] %= MOD;
                }
            }

            swap(dp, dp_prev);
        }

        return dp_prev[n][minProfit];

    }
};
// @lc code=end

