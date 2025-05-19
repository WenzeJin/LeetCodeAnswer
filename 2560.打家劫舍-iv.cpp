/*
 * @lc app=leetcode.cn id=2560 lang=cpp
 *
 * [2560] 打家劫舍 IV
 */

// @lc code=start
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // 二分 + DP

    int houses(vector<int>& nums, int maxSteal) {
        // 用几个滚动变量保存dp结果
        int last = 0, curr = 0, next = nums[0] <= maxSteal;
        for (int i = 1; i < nums.size(); i++) {
            last = curr;
            curr = next;
            next = max(last + (nums[i] <= maxSteal ? 1 : 0), curr);
        }
        return next;
    }

    int minCapability(vector<int>& nums, int k) {
        // 这个题要求至少偷 k 个房屋时 每个房屋窃取金额的最大值的最小值
        // 换个角度，如果限制窃取的最大值，就会得到最多能偷的房屋数，这个数量必须要 >= k, 且能偷的房屋数 f(maxSteal) 随 maxSteal 单调增。所以可以进行二分搜索。
        // 原先题意：确定 k 找到一个偷法，使得偷的最大值最小，输出这个最小值
        // 改为：确定一个最小的最大值，使得在这其中能找到偷 k 个的偷法
        int lo = *min_element(nums.begin(), nums.end());
        int hi = *max_element(nums.begin(), nums.end());
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (houses(nums, mid) < k) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return lo;
    }
};
// @lc code=end

