/*
 * @lc app=leetcode.cn id=1035 lang=cpp
 *
 * [1035] Uncrossed Lines
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        // dp[i][j] 表示 nums1[0..i-1] nums2[0..j-1] 的最多线条数
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); // 不连线
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
                }
            }
        }

        return dp[n][m];
    }
};
// @lc code=end

