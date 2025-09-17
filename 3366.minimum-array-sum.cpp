/*
 * @lc app=leetcode.cn id=3366 lang=cpp
 *
 * [3366] Minimum Array Sum
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
        int n = nums.size();
        vector<int> pre(n);
        pre[0] = nums[0];
        for (int i = 1; i < n; i++) {
            pre[i] = pre[i - 1] + nums[i];
        }

        // dp[i][j][k] 代表前 i 个数使用 j 词 op1 和 k 次 op2 能达到的最小数组和，i 可以压缩；
        vector<vector<int>> dp_prev(op1 + 1, vector<int>(op2 + 1));
        vector<vector<int>> dp(op1 + 1, vector<int>(op2 + 1));
        for (int i = 0; i < n; i++) {
            swap(dp_prev, dp);
            dp[0][0] = nums[i] + dp_prev[0][0];
            for (int j = 0; j <= op1; j++) {
                for (int k = 0; k <= op2; k++) {
                    dp[j][k] = nums[i] + dp_prev[j][k];
                    // do op1
                    if (j > 0) {
                        dp[j][k] = min(dp[j][k], (int)ceil((double)nums[i] / 2) + dp_prev[j - 1][k]);
                    }
                    // dp op2
                    if (k > 0 && nums[i] >= k) {
                        dp[j][k] = min(dp[j][k], nums[i] - k + dp_prev[j][k - 1]);
                    }
                    // dp op1 & op2
                    if (j > 0 && k > 0) {
                        // first do op1 then op2
                        int temp = nums[i];
                        temp = ceil((double) temp / 2);
                        if (temp < k) goto R;
                        temp -= k;
                        dp[j][k] = min(dp[j][k], temp + dp_prev[j - 1][k - 1]);
                        
                        // op2 then op1
                        R:
                        temp = nums[i];
                        if (temp < k) goto E;
                        temp -= k;
                        temp = ceil((double) temp / 2);
                        dp[j][k] = min(dp[j][k], temp + dp_prev[j - 1][k - 1]);

                        E:
                        temp = 0;
                    }
                }
            }
        }
        return dp[op1][op2];
    }
};
// @lc code=end

