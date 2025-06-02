/*
 * @lc app=leetcode.cn id=2439 lang=cpp
 *
 * [2439] Minimize Maximum of Array
 */

#include <climits>
#include <vector>
#include <numeric>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {

public:
    int minimizeArrayValue(vector<int>& nums) {
        // 实际上除了第一个以外的数字都可以降低到任意的数值，但是后面减小的总和（原总和-调整后总和）由除了最后一个数字以外的数字承担(只能由前面的数字承担)
        auto check = [&](int maxTarget) -> bool {
            if (nums[0] > maxTarget) {
                return false;
            }
            long long over = max(0LL, (long long)nums[nums.size() - 1] - maxTarget);
            for (int i = nums.size() - 2; i >= 0; i--) {
                over = max(0LL, over + (nums[i] - maxTarget));
            }
            return over == 0;
        };
        
        // invariant: r true l false
        int r = accumulate(nums.begin(), nums.end(), 0, [](int maxV, int curr) { return max(maxV, curr); });
        int l = accumulate(nums.begin(), nums.end(), INT_MAX, [](int minV, int curr) { return min(minV, curr); }) - 1;

        while (l + 1 < r) {
            int mid = l + (r - l) / 2;
            mid = mid == l ? l + 1: mid;
            if (check(mid)) {
                r = mid;
            } else {
                l = mid;
            }
        }

        return r;
    }
};
// @lc code=end

