/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */

// @lc code=start
#include <numeric>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) {
            return false;
        }

        // vector<vector<bool>> dp(nums.size() + 1, vector<bool>(sum + 1));
        // // dp[i][j] means we can select a subset until nums[i - 1] which has a sum of j
        // for (int i = 1; i <= nums.size(); i++) {
        //     for (int j = 0; j <= sum; j++) {
        //         if (j < nums[i - 1]) {
        //             dp[i][j] = dp[i - 1][j]; // 不能选择
        //         } else if (j == nums[i - 1]) {
        //             dp[i][j] = true;    // 一定可以
        //         } else {
        //             dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];  // 选或不选
        //         }
        //     }
        // }

        // return dp[nums.size()][sum / 2];
        // 我们可以将上面的做法降到一维
        vector<bool> dp(sum + 1);

        for (int i = 1; i <= nums.size(); i++) {
            for (int j = sum; j >= 0; j--) {
                // j 从后向前，就不会覆盖掉想要的数据
                // if (j < nums[i - 1]) {
                //     dp[j] = dp[j]
                // }
                if (j == nums[i - 1]) {
                    dp[j] = true;
                } else if (j > nums[i - 1]) {
                    dp[j] = dp[j] || dp[j - nums[i - 1]];
                }
            }
        }

        return dp[sum / 2];
    }
};
// @lc code=end

