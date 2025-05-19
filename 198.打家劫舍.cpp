/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size());

        if (nums.size() == 1) {
            return nums[0];
        }

        if (nums.size() == 2) {
            return max(nums[0], nums[1]);
        }

        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]); // 偷与不偷
        }
        return dp[nums.size() - 1];
    }
};
// @lc code=end

