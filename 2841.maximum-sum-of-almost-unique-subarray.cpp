/*
 * @lc app=leetcode.cn id=2841 lang=cpp
 *
 * [2841] Maximum Sum of Almost Unique Subarray
 */

#include <climits>
#include <vector>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        unordered_map<int, int> window;
        long long sum = 0;
        long long maxVal = LLONG_MIN;

        for (int i = 0; i < nums.size(); i++) {
            if (i < k) {
                window[nums[i]]++;
                sum = sum + nums[i];
            } else {
                // remove and insert
                window[nums[i - k]]--;
                window[nums[i]]++;
                sum = sum + nums[i] - nums[i - k];
                if(window[nums[i - k]] == 0) {
                    window.erase(nums[i - k]);
                }
            }

            // 判断窗口是否满足条件
            if (i >= k - 1) {
                if (window.size() >= m) {
                    maxVal = max(sum, maxVal);
                }
            }
            
        }

        return maxVal == LLONG_MIN ? 0 : maxVal;
    }
};
// @lc code=end

