/*
 * @lc app=leetcode.cn id=188 lang=cpp
 *
 * [188] Best Time to Buy and Sell Stock IV
 */

#include <algorithm>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        // dp[i][j] 表示各个状态下的最大收入，共 2k + 1 状态。
        int n = prices.size();
        int m = 2 * k + 1;
        vector<int> dp(m, INT_MIN / 2);

        dp[0] = 0;

        for (int i = 0; i < n; i++) {
            for (int j = m - 1; j > 0; j--) {
                if (j % 2 == 0) {
                    // 转换为卖出状态
                    dp[j] = max(dp[j], dp[j - 1] + prices[i]);
                } else {
                    // 转换为买入状态
                    dp[j] = max(dp[j], dp[j - 1] - prices[i]);
                }
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};
// @lc code=end

