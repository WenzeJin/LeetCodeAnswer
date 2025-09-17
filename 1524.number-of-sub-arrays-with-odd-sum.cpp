/*
 * @lc app=leetcode.cn id=1524 lang=cpp
 *
 * [1524] Number of Sub-arrays With Odd Sum
 */

#include <vector>
#include <numeric>

using namespace std;

// @lc code=start
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        vector<int> prefix(n + 1);
        partial_sum(arr.begin(), arr.end(), prefix.begin() + 1);

        vector<vector<int>> cnt(n + 1, vector<int>(2)); // 表示 i 之后前缀和为奇数和偶数的数目

        for (int i = n - 1; i >= 0; --i) {
            if (prefix[i + 1] % 2 == 0) {
                cnt[i][0] = cnt[i + 1][0] + 1;
                cnt[i][1] = cnt[i + 1][1];
            } else {
                cnt[i][1] = cnt[i + 1][1] + 1;
                cnt[i][0] = cnt[i + 1][0];
            }
        }

        int res = 0;
        constexpr int MOD = 1e9 + 7;
        for (int i = 0; i < n; i++) {
            if (prefix[i] % 2 == 0) {
                res += cnt[i][1];
            } else {
                res += cnt[i][0];
            }
            res %= MOD;
        }

        return res;
    }
};
// @lc code=end

