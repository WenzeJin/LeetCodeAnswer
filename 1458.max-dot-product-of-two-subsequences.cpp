/*
 * @lc app=leetcode.cn id=1458 lang=cpp
 *
 * [1458] Max Dot Product of Two Subsequences
 */

#include <climits>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>> dp_sel(n + 1, vector<int>(m + 1));
        vector<vector<int>> dp_not(n + 1, vector<int>(m + 1));
        for (int i = 0; i <= n; i++) {
            dp_not[i][0] = INT_MIN;
        }
        for (int j = 0; j <= m; j++) {
            dp_not[0][j] = INT_MIN;
        }
        dp_not[1][1] = nums1[0] * nums2[0];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (i != 0 && j != 0) {
                    dp_not[i][j] = max(dp_not[i - 1][j], dp_not[i][j - 1]);
                    dp_not[i][j] = max(dp_not[i][j], dp_sel[i - 1][j - 1] + nums1[i - 1] * nums2[j - 1]);
                }
                dp_sel[i][j] = max(dp_sel[i - 1][j], dp_sel[i][j - 1]);
                dp_sel[i][j] = max(dp_sel[i][j], dp_sel[i - 1][j - 1] + nums1[i - 1] * nums2[j - 1]);
            }
        }
        return dp_not[n][m];
    }
};
// @lc code=end

