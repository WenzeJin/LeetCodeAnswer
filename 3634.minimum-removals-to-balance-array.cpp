/*
 * @lc app=leetcode.cn id=3634 lang=cpp
 *
 * [3634] Minimum Removals to Balance Array
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
    bool valid(vector<int>& nums, int k, int limit) {
        int n = nums.size();
        for (int i = 0; i + n - k - 1 < n; i++) {
            if ((long long)nums[i + n - k - 1] <= (long long)nums[i] * limit) {
                return true;
            }
        }
        return false;
    }
public:
    int minRemoval(vector<int>& nums, int k) {
        // 由于移除 n - 1 个一定能完成目标，而且移除大于某个数之后都能完成目标，所以可以二分搜索
        // 每次如何在 O(n) 时间内验证是否可以移除？因为我们一定是移除首位的，若移除 k 个，我们需要在排序后的数组中验证所有 [i] [i + n - k - 1] 是否满足要求，如果满足，就可以只保留这其中的，去除这外面的。

        sort(nums.begin(), nums.end());

        int l = 0, r = nums.size() - 1;
        // r 始终能完成目标

        while (l < r) {
            // 验证与更新
            int m = (l + r) / 2;
            if (valid(nums, m, k)) {
                r = m;
            } else {
                l = m + 1;
            }
        }

        return r;
    }
};
// @lc code=end

