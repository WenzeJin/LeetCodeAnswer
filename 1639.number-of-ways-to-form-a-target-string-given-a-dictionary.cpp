/*
 * @lc app=leetcode.cn id=1639 lang=cpp
 *
 * [1639] Number of Ways to Form a Target String Given a Dictionary
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int numWays(vector<string>& words, string target) {
        // dp[i][k] 表示用 words 中的前 k 个字符构建 target[0..i - 1] 的方法数量
        // 预处理 words 中的每一位各字符数量
        constexpr int MOD = 1e9 + 7;

        int sd = words.size();
        int l = words[0].length();
        int n = target.length();
        vector<vector<int>> index(l, vector<int>(26));
        for (auto& s: words) {
            for (int i = 0; i < s.length(); i++) {
                index[i][s[i] - 'a']++;
            }
        }

        vector<vector<int>> dp(n + 1, vector<int>(l + 1));
        dp[0][0] = 1;
        for (int k = 0; k <= l; k++) {
            dp[0][k] = 1;
        }
        for (int i = 1; i <= n; i++) {
            for (int k = 1; k <= l; k++) {
                // 不使用第 k - 1 位
                dp[i][k] = dp[i][k - 1];
                // 使用第 k - 1 位
                int choices = index[k - 1][target[i - 1] - 'a'];
                for (int i = 0; i < choices; i++) {
                    dp[i][k] += dp[i - 1][k - 1];
                    dp[i][k] %= MOD;
                }
            }
        }

        return dp[n][l];
    }
};
// @lc code=end

