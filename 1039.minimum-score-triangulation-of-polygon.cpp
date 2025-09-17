/*
 * @lc app=leetcode.cn id=1039 lang=cpp
 *
 * [1039] Minimum Score Triangulation of Polygon
 */

#include <climits>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        // dp[i][j] 表示 i j 之间的多边形的最小分数，此时 i j 已经练成一条边

        int n = values.size();
        vector<vector<int>> dp(n, vector<int>(n));

        for (int i = n - 1; i >= 0; i++) {
            for (int j = i + 2; j < n; j++) {
                int min_s = INT_MAX;
                for (int k = i + 1; k < j; k++) {
                    min_s = min(min_s, dp[i][k] + dp[k][j] + values[i] * values[j] * values[k]);
                }
                dp[i][j] = min_s;
            }
        }

        return dp[0][n - 1];
    }
};
// @lc code=end

