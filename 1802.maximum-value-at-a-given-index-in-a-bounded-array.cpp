/*
 * @lc app=leetcode.cn id=1802 lang=cpp
 *
 * [1802] Maximum Value at a Given Index in a Bounded Array
 */

// @lc code=start
class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        // 二分查找 nums[index] 的值，因为超过一个值后肯定无法满足

        int left = 0, right = maxSum + 1;

        auto check = [&](int maxVal) {
            int sum = 0;
            if (maxVal >= index + 1) {
                sum += (maxVal - index) * (index + 1) / 2;
            } else {
                sum += maxVal * (maxVal + 1) / 2;
            }
            int rl = n - index;
            if (maxVal >= rl) {
                sum += (maxVal - rl + 1) * (rl) / 2;
            } else {
                sum += maxVal * (maxVal + 1) / 2;
            }

            sum -= maxVal;
            return sum <= maxSum;
        };

        while (left < right - 1) {
            int mid = left + (right - left) / 2;
            if (check(mid)) {
                left = mid;
            } else {
                right = mid;
            }
        }

        return left;
    }
};
// @lc code=end

