/*
 * @lc app=leetcode.cn id=3423 lang=cpp
 *
 * [3423] Maximum Difference Between Adjacent Elements in a Circular Array
 */
#include <algorithm>
#include <vector>


using namespace std;

// @lc code=start
class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int maxVal = 0;
        for (int i = 1; i < nums.size(); i++) {
            maxVal = max(maxVal, abs(nums[i] - nums[i - 1]));
        }
        maxVal = max(maxVal, abs(nums[0] - nums[nums.size() - 1]));
        return maxVal;
    }
};
// @lc code=end

