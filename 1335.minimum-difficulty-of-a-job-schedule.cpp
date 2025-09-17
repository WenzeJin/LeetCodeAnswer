/*
 * @lc app=leetcode.cn id=1335 lang=cpp
 *
 * [1335] Minimum Difficulty of a Job Schedule
 */

#include <climits>
#include <vector>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        // dp[i][j] 表示将 job[i:] 后的分成 j 份的最小难度
        int n = jobDifficulty.size();
        vector<vector<int>> dp(n + 1, vector<int>(d + 1, INT_MAX / 2));
        dp[n][0] = 0;
        for (int i = n - 1; i >= 0; i --) {
            int max_d = 0;
            for (int k = i; k < n; k++) {
                max_d = max(max_d, jobDifficulty[k]);
                for (int j = 1; j <= d; j++) {
                    dp[i][j] = min(dp[i][j], max_d + dp[k + 1][j - 1]);
                }
            }
        }
        // for (auto& v: dp) {
        //     for (int x: v) {
        //         cout << x << " ";
        //     }
        //     cout << endl;
        // }
        return dp[0][d] < INT_MAX / 2 ? dp[0][d] : -1;
    }
};
// @lc code=end

