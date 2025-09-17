/*
 * @lc app=leetcode.cn id=2430 lang=cpp
 *
 * [2430] Maximum Deletions on a String
 */

#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int deleteString(string s) {
        // dp[i] 表示删除第 i - 1 个字符后的字符串所需的最大操作数。
        // dp[n] = 0
        // 每次要尽可能找前缀进行删除，否则只能全部删除
        // 需要快速判断 s[i...i + j] 和 s[i + j... i + 2j] 是否相同
        // 可以用 dp 预处理
        int n = s.length();
        vector<vector<int>> lcp(n + 1, vector<int>(n + 1)); // lcp[i][j] 是 s[i:] 和 s[j:] 的最长公共前缀
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (s[i] == s[j]) {
                    lcp[i][j] = lcp[i + 1][j + 1] + 1;
                }
            }
        }

        vector<int> dp(n + 1);
        for (int i = n - 1; i >= 0; i++) {
            dp[i] = 1; // 全部删除
            for (int k = 1; k <= (n - i) / 2; k++) {
                if (lcp[i][i + k] >= k) {
                    dp[i] = max(dp[i], dp[i + k] + 1);
                }
            }
        }
        return dp[0];
    }
};
// @lc code=end

