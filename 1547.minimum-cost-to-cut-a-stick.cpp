/*
 * @lc app=leetcode.cn id=1547 lang=cpp
 *
 * [1547] Minimum Cost to Cut a Stick
 */

#include <climits>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());

        int m = cuts.size();
        // dp[i][j] 为切除 cuts[i] - cuts[j] 的最小代价

        vector<vector<int>> dp(m, vector<int>(m));

        for (int i = m - 1; i >= 0; i--) {
            for (int j = i + 1; j < m; j++) {
                int min_c = INT_MAX;
                for (int k = i; k <= j; k++) {
                    min_c = min(dp[i][k] + dp[k][j], min_c);
                }
                dp[i][j] = min_c + cuts[j] - cuts[i];
            }
        }

        return dp[0][m - 1];
    }
};
// @lc code=end

