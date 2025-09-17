/*
 * @lc app=leetcode.cn id=3637 lang=cpp
 *
 * [3637] Trionic Array I
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int state = 0;
        int prev = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            switch (state) {
                case 0:
                if (nums[i] <= prev) {
                    return false;
                } else {
                    state = 1;
                }
                break;
                case 1:
                if (nums[i] < prev) {
                    state = 2;
                } else if (nums[i] == prev) {
                    return false;
                }
                break;
                case 2:
                if (nums[i] > prev) {
                    state = 3;
                } else if (nums[i] == prev) {
                    return false;
                }
                break;
                case 3:
                if (nums[i] <= prev) {
                    return false;
                }
                break;
            }
            prev = nums[i];
        }
        return state == 3;
    }
};
// @lc code=end

