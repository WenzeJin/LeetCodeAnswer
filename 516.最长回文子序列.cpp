/*
 * @lc app=leetcode.cn id=516 lang=cpp
 *
 * [516] 最长回文子序列
 */

// @lc code=start
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int longestPalindromeSubseq(string s) {
    // dp[i][j] means longest palindrome subseq in s[i...j]

    // 这里利用状态压缩把二维 dp 数组压到一维线性 dp
    vector<int> dpl(s.length());

    dpl[s.length() - 1] = 1; // [l - 1][l - 1]

    // dp[i][j] = max(dp[i + 1][j], dp[i][j - 1], dp[i + 1][j - 1] + 1 if s[i] == s[j])
    for (int i = s.length() - 1; i >= 0; i--) {
      int pre = dpl[i];
      dpl[i] = 1;
      for (int j = i + 1; j < s.length(); j++) {
        int temp = dpl[j];
        dpl[j] = max(temp, dpl[j - 1]);
        if (s[i] == s[j]) {
          dpl[j] = max(dpl[j], pre + 2);
        }
        pre = temp;
      }
    }

    return dpl[s.length() - 1];
  }
};
// @lc code=end

