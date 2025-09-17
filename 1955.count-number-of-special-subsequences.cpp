/*
 * @lc app=leetcode.cn id=1955 lang=cpp
 *
 * [1955] Count Number of Special Subsequences
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int countSpecialSubsequences(vector<int>& nums) {
        // 用 dp 解决，如果dp代表以 i 结尾的特殊子序列个数，那么可以分 四个状态：未选，正在选0，正在选1，正在选2
        // 但是这样 dp 的更新需要遍历之前所有位置，不划算。
        // 可以分八个状态，在前四个状态的基础上，分别表示 nums[i] 是否被选中。
        // dp 可以被压缩。
        constexpr int MOD = 1e9 + 7;
        vector<vector<int>> dp(2, vector<int>(4)), dp_prev(2, vector<int>(4));
        dp[0][0] = 1; // 其余状态初始不合法，均为0
        int n = nums.size();
        for (int i = 1; i <= n; i++) {
            swap(dp, dp_prev);
            for (int j = 0; j < 4; j++) {
                // 此处不选，上一位可选可不选
                dp[0][j] = dp_prev[0][j] + dp_prev[1][j];
                dp[0][j] %= MOD;
            }
            // 此处选，得看数字 0 前面可以为 0 或者不选，1 前面 可以为 1或 0
            dp[1][0] = 0; // 不可能
            for (int j = 1; j < 4; j++) {
                if (j == nums[i - 1] + 1) {
                    dp[1][j] = ((dp_prev[1][j] + dp_prev[1][j - 1]) % MOD + dp_prev[0][j]) % MOD + dp_prev[0][j - 1];
                    dp[1][j] %= MOD;
                } else {
                    // 不可能状态，不可能这一位选了1，子序列在选0状态 等等。
                    dp[1][j] = 0;
                }
            }
        }
        return (dp[0][3] + dp[1][3]) % MOD;
    }
};
// @lc code=end

