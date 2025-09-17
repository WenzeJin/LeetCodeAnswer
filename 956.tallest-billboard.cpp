/*
 * @lc app=leetcode.cn id=956 lang=cpp
 *
 * [956] Tallest Billboard
 */

#include <vector>
#include <unordered_map>
#include <numeric>

using namespace std;

// @lc code=start

// class Solution {
// public:
//     int tallestBillboard(vector<int>& rods) {
//         // 也就是找一个最大的子集，首先这个子集能被平分为两半，其次它最大。
//         // 该问题变为，是否能找到一堆东西，填满两个容量为 n 的包，用 dp[i][j][k] 作为使用前 i 个rods 是否能满足高度分别为 j 和 k 的两个柱子。 i 可以被压缩
        
//         int sum = accumulate(rods.begin(), rods.end(), 0);

//         int max_h = sum / 2;
//         vector<vector<bool>> dp_prev(max_h + 1, vector<bool>(max_h + 1));
//         vector<vector<bool>> dp(max_h + 1, vector<bool>(max_h + 1));

//         dp_prev[0][0] = true;

//         for (int i = 1; i <= rods.size(); i++) {
//             dp[0][0] = true;
//             for (int j = 0; j <= max_h; j++) {
//                 for (int k = 0; k <= max_h; k++) {
//                     dp[j][k] = dp_prev[j][k];
//                     if (j >= rods[i - 1]) {
//                         dp[j][k] = dp[j][k] || dp_prev[j - rods[i - 1]][k];
//                     }
//                     if (k >= rods[i - 1]) {
//                         dp[j][k] = dp[j][k] || dp_prev[j][k - rods[i - 1]];
//                     }
//                 }
//             }
//             swap(dp, dp_prev);
//         }

//         int ans = 0;
//         for (int i = 1; i <= max_h; i++) {
//             if (dp_prev[i][i]) {
//                 ans = i;
//             }
//         }
//         return ans;
//     }
// };

class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        // 上面的复杂度太高，本质上是一种重复计算，因为很多值都不可能计算到。将 0 - 1 背包问题扩展，每一位有三种计算方式 + - 0，最终我们要使总和为 0 就可以完成任务。
        // 问题就是要求，当总和为 0 时的最大正数和。
        // dp[i][j] 表示当使用前 i 个rods 是，总和为 j 时的最大正数和。
        // 可以压缩一维
        // dp[i][j] = (dp[i - 1][j] (选0), dp[i - 1][j - rods[i - 1]] + rods[i - 1] (选+), dp[i - 1][j + rods[i - 1]] （选 -）)
        // 可以以另一种角度去更新 dp，当遇到一个新的数时，从现有的 dp[i][j] 出发，加上或减去这个数，并取最大。
        unordered_map<int, int> dp;

        dp[0] = 0;

        for (int i = 0; i < rods.size(); i++) {
            auto dp_prev = unordered_map<int, int>(dp);
            for (auto& kv: dp_prev) {
                // chose 0 do nothing
                // chose +
                dp[kv.first + rods[i]] = max(dp[kv.first + rods[i]], kv.second + rods[i]);
                // chose -
                dp[kv.first - rods[i]] = max(dp[kv.first - rods[i]], kv.second);
            }
        }
        
        return dp[0];
        
    } 
};
// @lc code=end

