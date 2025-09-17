/*
 * @lc app=leetcode.cn id=1444 lang=cpp
 *
 * [1444] Number of Ways of Cutting a Pizza
 */

#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int ways(vector<string>& pizza, int K) {
        // dp[k][i][j] 表示将含 pizza[i][j] 的右下角切为 k 块的方案数
        // 预先处理 cnt[i][j] 表示以 i,j 为左上角的矩形苹果数量
        int n = pizza.size();
        int m = pizza[0].length();
        vector<vector<int>> cnt(n + 1, vector<int>(m + 1));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int curr = pizza[i][j] == 'A';
                cnt[i][j] = curr + cnt[i + 1][j] + cnt[i][j + 1] - cnt[i + 1][j + 1];
            }
        }

        vector<vector<vector<int>>> dp(K + 1, vector<vector<int>>(n + 1, vector<int>(m + 1)));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (cnt[i][j] > 0) {
                    dp[1][i][j] = 1;
                }
                for (int k = 2; k <= K; k++) {
                    for (int ii = i + 1; ii < n; ii++) {
                        if (cnt[ii][j] < cnt[i][j])
                            dp[k][i][j] += dp[k - 1][ii][j];
                    }
                    for (int jj = j + 1; jj < m; jj++) {
                        if (cnt[i][jj] < cnt[i][j]) {
                            dp[k][i][j] += dp[k - 1][i][jj];
                        }
                    }
                }
            }
        }

        return dp[K][0][0];
    }
};
// @lc code=end

