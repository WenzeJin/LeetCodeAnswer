/*
 * @lc app=leetcode.cn id=3316 lang=cpp
 *
 * [3316] Find Maximum Removals From Source String
 */

#include <vector>
#include <unordered_set>

using namespace std;

// @lc code=start
class Solution {
public:
    int maxRemovals(string source, string pattern, vector<int>& targetIndices) {
        // 问题可转化为 对于 source 的每一位 i，是否用来匹配 pattern 第 j 位，如果不能匹配，可以去掉，分为白白去掉和在删除列表里的去掉。如果可以匹配，则有匹配和去掉两种选择。
        // 最后要确保 source 匹配了 pattern， dp[i][j] 表示用 source[0..i - 1] 匹配 pattern[0..j - 1] 最多删除位数。 dp[0][0] 初始化为 0，其余初始化为 INT_MIN，表示不能匹配，结果不合理。

        int n = source.length();
        int m = pattern.length();
        unordered_set<int> target;
        for (int x: targetIndices) {
            target.insert(x);
        }
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MIN));
        dp[0][0] = 0;
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                // 放弃
                if (i > 0) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j] + (int)target.count(i - 1));
                }
                // 不放弃
                if (i > 0 && j > 0 && source[i - 1] == pattern[j - 1]) {
                    dp[i][j] =max(dp[i][j], dp[i - 1][j - 1]);
                } 
            }
        }
        return dp[n][m];
    }
};
// @lc code=end

