/*
 * @lc app=leetcode.cn id=2958 lang=cpp
 *
 * [2958] Length of Longest Subarray With at Most K Frequency
 */

#include <vector>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        // 滑动窗口，越短越满足，确定窗口右端
        int left = 0, right = 0;
        unordered_map<int, int> cnt;

        int res = 0;

        for (right = 0; right < nums.size(); right++) {
            int x = nums[right];
            // move in
            cnt[x]++;
            while (cnt[x] > k) {
                // move out to fit
                int x = nums[left];
                cnt[x]--;
                left++;
            }

            res = max(res , right - left + 1);
        }

        return res;
    }
};
// @lc code=end

