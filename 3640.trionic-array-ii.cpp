/*
 * @lc app=leetcode.cn id=3640 lang=cpp
 *
 * [3640] Trionic Array II
 */

#include <climits>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        // 状态机 DP，分为四个状态，代表以 nums[i] 结尾，并且 nums[i] 正处于 {起始、上升段、下降段、第二上升段} 的最大子数组和。
        int n = nums.size();
        vector<long long> dp(4, LLONG_MIN);
        vector<long long> dp_prev(4, LLONG_MIN);
        dp[0] = nums[0];
        long long max_val = LLONG_MIN;
        for (int i = 1; i < n; i++) {
            swap(dp, dp_prev);
            dp[0] = nums[i];
            dp[1] = dp[2] = dp[3] = LLONG_MIN;
            if (nums[i] > nums[i - 1]) {
                long long max1 = max(dp_prev[0], dp_prev[1]);
                dp[1] = max1 != LLONG_MIN ? max1 + nums[i] : LLONG_MIN;
                long long max2 = max(dp_prev[2], dp_prev[3]);
                dp[3] = max2 != LLONG_MIN ? max2 + nums[i] : LLONG_MIN;
            } else if (nums[i] < nums[i - 1]) {
                long long max1 = max(dp_prev[1], dp_prev[2]);
                dp[2] = max1 != LLONG_MIN ? max1 + nums[i] : LLONG_MIN;
            }
            max_val = max(dp[3], max_val);
        }
        
        return max_val == LLONG_MIN ? -1 : max_val;
    }
};
// @lc code=end

