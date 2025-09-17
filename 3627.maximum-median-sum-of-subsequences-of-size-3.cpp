/*
 * @lc app=leetcode.cn id=3627 lang=cpp
 *
 * [3627] Maximum Median Sum of Subsequences of Size 3
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        n = n / 3;
        long long ans = 0;
        for (int i = 1; i <= n; i++) {
            ans += nums[n - 2 * i];
        }
        return ans;
    }
};
// @lc code=end

