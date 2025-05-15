/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

// @lc code=start
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> max_until(nums.size());

        if (nums.size() == 0) {
            return 0;
        }

        for (auto& x: max_until) {
            x = 1;
        }

        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                // 严格递增
                if (nums[j] < nums[i]) {
                    max_until[i] = max(max_until[i], max_until[j] + 1);
                }
            }
        }

        return *max_element(max_until.begin(), max_until.end());
    }
};
// @lc code=end

