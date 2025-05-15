/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size());
        // dp[i] is the max sum of any sub array ending with nums[i]
        if (nums.size() == 0) {
            return 0;
        }

        dp[0] = nums[0];

        for (int i = 0; i < nums.size(); i++) {
            // 自己另起炉灶或者接着前面的继续走，既然接着前面的走，肯定接上最大值
            dp[i] = max(nums[i], nums[i] + dp[i - 1]);
        }

        return *max_element(dp.begin(), dp.end());
    }
};
// @lc code=end

