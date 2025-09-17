/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] Best Time to Buy and Sell Stock III
 */

#include <algorithm>
#include <vector>

using namespace std;

// @lc code=start
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         // 分状态 dp，可以进行两次买卖，每次又分为已买入和已卖出两个状态，共 5 个状态

//         int n = prices.size();
//         vector<vector<int>> dp(n + 1, vector<int>(5));

//         for (int j = 1; j < 5; j++) {
//             dp[0][j] = INT_MIN / 2; // 不合法状态
//         }

//         for (int i = 1; i <= n; i++) {
//             for (int j = 1; j < 5; j++) {
//                 if (j % 2 == 1) {
//                     // 此时买入状态
//                     dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] - prices[i - 1]);
//                 } else {
//                     // 此时卖出状态
//                     dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] + prices[i - 1]);
//                 }
//             }
//         }

//         return *max_element(dp[n].begin(), dp[n].end());
//     }
// };

// 优化到极致

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy1 = -prices[0], sell1 = 0;
        int buy2 = -prices[0], sell2 = 0;
        for (int i = 1; i < n; ++i) {
            buy1 = max(buy1, -prices[i]);
            sell1 = max(sell1, buy1 + prices[i]);
            buy2 = max(buy2, sell1 - prices[i]);
            sell2 = max(sell2, buy2 + prices[i]);
        }
        return sell2;
    }
};
// @lc code=end

