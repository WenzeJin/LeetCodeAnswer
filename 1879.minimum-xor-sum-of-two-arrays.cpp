/*
 * @lc app=leetcode.cn id=1879 lang=cpp
 *
 * [1879] Minimum XOR Sum of Two Arrays
 */

#include <climits>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> dp(1 << n, INT_MAX);

        for (int mask = 0; mask < (1 << n); ++mask) {
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    dp[mask] = min(dp[mask], dp[mask ^ (1 << i)] + nums1[__builtin_popcount(mask) - 1] ^ nums2[i]);
                }
            }
        }

        return dp[(1 << n) - 1];
    }
};
// @lc code=end

