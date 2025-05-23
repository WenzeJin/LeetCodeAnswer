/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

#include <deque>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> window;
        // big -> small
        vector<int> res;
        int l = -1, r = -1;

        for (int i = 0; i < nums.size(); i++) {
            if (i < k) {
                while (!window.empty() && nums[window.back()] <= nums[i]) window.pop_back();
                window.push_back(i);
                l = 0; r = i;
                if (i == k - 1) {
                    res.push_back(nums[window.front()]);
                }
            } else {
                if (window.front() == l) {
                    window.pop_front();
                }
                l++;
                while (!window.empty() && nums[window.back()] <= nums[i]) window.pop_back();
                window.push_back(i);
                r = i;
                res.push_back(nums[window.front()]);
            }
        }

        return res;
    }
};
// @lc code=end

