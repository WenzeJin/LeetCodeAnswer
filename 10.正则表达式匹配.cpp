/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */

// @lc code=start

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  bool isMatch(string s, string p) {

    // dp[i][j] means s[0..=i-1] matches p[0..=j-1], if p[i] is 'a' and p[i + 1]
    // is '*', we see them as a whole
    // if p[j - 1] is '*' dp[i][j] = dp[i][j - 1]
    // if p[j - 1] is 'a*' dp[i][j] = dp[i - 1][j] && s[i - 1] == p[j - 1] ||
    // dp[i - 1][j - 1] && s[i - 1] == p[j - 1] || dp[i][j - 1]
    // if p[j - 1] is 'a' and p[j] is not '*' dp[i][j] = dp[i - 1][j - 1] && s[i
    // - 1] == p[j - 1]
    // if p[j - 1] is '.' then dp[i][j] = dp[i - 1][j - 1]
    vector<vector<bool>> dp(s.length() + 1, vector<bool>(p.length() + 1));

    dp[0][0] = true;

    for (int i = 0; i <= s.length(); ++i) {
      for (int j = 1; j <= p.length(); ++j) {
        if (p[j - 1] == '*') {
          dp[i][j] = dp[i][j - 1];
        } else {
          if (i > 0) {
            bool match = s[i - 1] == p[j - 1] || p[j - 1] == '.';
            if (j < p.length() && p[j] == '*') {
              dp[i][j] =
                  ((dp[i - 1][j] || dp[i - 1][j - 1]) && match) ||
                  dp[i][j - 1];
            } else {
              dp[i][j] = dp[i - 1][j - 1] && match;
            }
          } else {
            // 这里要处理特殊情况，即s为空的情况，s为空仍然可以匹配使用*的模式
            if (j < p.length() && p[j] == '*') {
              dp[i][j] = dp[i][j - 1];
            } else {
              dp[i][j] = false;
            }
          }
        }
      }
    }
    return dp[s.length()][p.length()];
  }
};
// @lc code=end

