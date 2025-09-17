/*
 * @lc app=leetcode.cn id=44 lang=cpp
 *
 * [44] Wildcard Matching
 */

#include <string>
#include <vector>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1));

        dp[0][0] = true;
        for (int i = 0; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (p[j] == '?') {
                    if (i > 0)
                        dp[i][j] = dp[i - 1][j - 1];
                    else
                        dp[i][j] = false;
                } else if (p[j] == '*') {
                    if (i == 0)
                        dp[i][j] = dp[i][j - 1];
                    else {
                        for (int k = 0; k <= i; k++) {
                            if (dp[k][j - 1]) {
                                dp[i][j] = true;
                                break;
                            }
                        }
                    }
                } else {
                    if (s[i] == p[j])
                        dp[i][j] = dp[i - 1][j - 1];
                    else
                        dp[i][j] = false;
                }
            }
        }
        for (auto& v: dp) {
            for (bool t: v) {
                cout << (t ? "t" : "f") << " ";
            }
            cout << endl;
        }

        return dp[n][m];
    }
};
// @lc code=end

