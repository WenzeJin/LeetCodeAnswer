/*
 * @lc app=leetcode.cn id=918 lang=cpp
 *
 * [918] Maximum Sum Circular Subarray
 */

#include <climits>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        // 对于环状的，做两圈就行了。但是这里不行，因为要求不能重复使用，如果只是简单做两圈，有的数会被重复计算。反过来看，如果是首尾相接的子数组，那么实际上就是中间挖空，找一个最小的空就可以了，同时也要和普通的子数组取最大的一个。

        int tot = 0;
        int currMin, currMax;
        int minVal, maxVal;
        currMin = currMax = 0;
        minVal = 0;
        maxVal = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            currMin = min(currMin, 0) + nums[i];
            currMax = max(currMax, 0) + nums[i];
            minVal = min(minVal, currMin);
            maxVal = max(maxVal, currMax);
            tot += nums[i];
        }
        return tot == minVal ? maxVal : max(maxVal, tot - minVal);
    }
};
// @lc code=end

