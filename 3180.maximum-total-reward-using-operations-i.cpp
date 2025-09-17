/*
 * @lc app=leetcode.cn id=3180 lang=cpp
 *
 * [3180] Maximum Total Reward Using Operations I
 */

#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    int maxTotalReward(vector<int>& rewardValues) {
        // 0-1 背包问题，排序后从小数字开始优先组合，dp[i][j]表示是否能用前 i 个数组成总和 j。
        // 如果不选，则转化为问题 dp[i - 1][j]
        // 如果选，必须满足 value[i] <= j < value[i] * 2; 转化为 dp[i - 1][j - value[i]]
        
        sort(rewardValues.begin(), rewardValues.end());

        int n = rewardValues.size();
        int m = rewardValues[n - 1];
        m = 2 * m;
        
        vector<vector<bool>> dp(n, vector<bool>(m));

        for (int i = 0; i < n; i++) {
            dp[i][0] = true;
        }
        for (int j = 1; j < m; j++) {
            if (j != rewardValues[0]) {
                dp[0][j] = false;
            } else {
                dp[0][j] = true;
            }
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (j >= rewardValues[i] && j < rewardValues[i] * 2) {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - rewardValues[i]];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        int ans = 0;
        for (int j = 1; j < m; j++) {
            if (dp[n - 1][j]) {
                ans = j;
            }
        }
        return ans;
    }
};
// @lc code=end

