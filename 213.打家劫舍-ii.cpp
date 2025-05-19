/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    int robRange(vector<int>& nums, int start, int end) {
        // 求区间内的最大收获
        if (start == end) {
            return nums[start];
        }
        if (end == start + 1) {
            return max(nums[start], nums[end]);
        }
        vector<int> dp(end - start + 1);
        dp[0] = nums[start];
        dp[1] = max(nums[start], nums[start + 1]);
        for (int i = 2; start + i <= end; i++) {
            dp[i] = max(dp[i - 2] + nums[start + i], dp[i - 1]);
        }
        return dp[end - start];
    }


    int rob(vector<int>& nums) {
        // 既然首位不能同时偷，那么要么首不偷，要么尾不偷
        if (nums.size() == 1) {
            return nums[0];
        }
        return max(
            robRange(nums, 1, nums.size() - 1),
            robRange(nums, 0, nums.size() - 2)
        );
    }
};
// @lc code=end

