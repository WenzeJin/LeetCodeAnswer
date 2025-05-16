/*
 * @lc app=leetcode.cn id=1312 lang=cpp
 *
 * [1312] 让字符串成为回文串的最少插入次数
 */

// @lc code=start

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int minInsertions(string s) {
    // vector<vector<int>> dp(s.length(), vector<int>(s.length()));
    // // dp[i][j] means min ops needed for s[i..=j]
    // for (int i = 0; i < s.length(); i++) {
    //   dp[i][i] = 0;
    // }

    // for (int i = s.length() - 1; i >= 0; --i) {
    //   for (int j = i + 1; j < s.length(); ++j) {
    //     dp[i][j] = min(dp[i + 1][j] + 1, dp[i][j - 1] + 1);
    //     if (s[i] == s[j]) {
    //       dp[i][j] = min(dp[i][j], dp[i + 1][j - 1]);
    //     }
    //   }
    // }

    // return dp[0][s.length() - 1];

    // 利用状态压缩优化上面的代码

    vector<int> dpl(s.length());

    for (int i = s.length() - 1; i >= 0; --i) {
      int prev = dpl[i];
      for (int j = i + 1; j < s.length(); ++j) {
        int temp = dpl[j];
        dpl[j] = min(temp + 1, dpl[j - 1] + 1);
        if (s[i] == s[j]) {
          dpl[j] = min(dpl[j], prev);
        }
        prev = temp;
      }
    }

    return dpl[s.length() - 1];
  }
};
// @lc code=end

