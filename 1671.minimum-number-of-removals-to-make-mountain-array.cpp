/*
 * @lc app=leetcode.cn id=1671 lang=cpp
 *
 * [1671] Minimum Number of Removals to Make Mountain Array
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        // 山形数组要求先上升再下降，那么求两个 LIS 即可。
        int n = nums.size();
        vector<int> dp1(n);
        vector<int> dp2(n);
        dp1[0] = 1;
        dp2[n - 1] = 1;
        for (int i = 1; i < n; i++) {
            dp1[i] = 1;
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    dp1[i] = max(dp1[i], dp1[j] + 1);
                }
            }
        }
        for (int i = n - 2; i >= 0; i--) {
            dp2[i] = 1;
            for (int j = n - 1; j > i; j--) {
                if (nums[j] < nums[i]) {
                    dp2[i] = max(dp2[i], dp2[j] + 1);
                }
            }
        }
        int max_l = 0;
        for (int i = 0; i < n; i++) {
            if (dp1[i] > 1 && dp2[i] > 1)
                max_l = max(max_l, dp1[i] + dp2[i] - 1);
        }
        return n - max_l;
    }
};
// @lc code=end

