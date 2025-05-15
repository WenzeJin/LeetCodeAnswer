/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] 最长公共子序列
 */

// @lc code=start
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1));

        if (text1.empty() || text2.empty()) {
            return 0;
        }

        // dp[i][j] 为 text1[1..=i] text2[1..=j] 的 LCS 长度 这里我们认为下标1开始，比较好处理
        for (int i = 1; i <= text1.size(); i++) {
            for (int j = 1; j <= text2.size(); j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    // 相同，可以作为 LCS 的一份子
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    // 不相同，其中某个一定不在 LCS 中
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[text1.size()][text2.size()];
    }
};
// @lc code=end

