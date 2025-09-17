/*
 * @lc app=leetcode.cn id=2369 lang=cpp
 *
 * [2369] Check if There is a Valid Partition For The Array
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    bool validPartition(vector<int>& nums) {
        // 枚举每次的划分情况，dp[i] 表示前 i 项是否存在有效划分。
        int n = nums.size();
        if (n < 2) {
            return false;
        }
        vector<bool> dp(n + 1);
        dp[0] = true;
        for (int i = 2; i <= n; i++) {
            if (nums[i - 1] == nums[i - 2]) {
                dp[i] = dp[i] || dp[i - 2];
            }
            if (i > 2) {
                if ((nums[i - 1] == nums[i - 2] && nums[i - 1] == nums[i - 3]) ||
                (nums[i - 1] - nums[i - 3] == 2 && nums[i - 1] - nums[i - 2] == 1)) {
                    dp[i] = dp[i] || dp[i - 3];
                }
            }
        }
        return dp[n];
    }
};
// @lc code=end

