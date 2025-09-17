/*
 * @lc app=leetcode.cn id=456 lang=cpp
 *
 * [456] 132 Pattern
 */

#include <climits>
#include <vector>
#include <stack>

using namespace std;

// @lc code=start
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        // 从右往左枚举 1
        // 每次将新元素作为 2 的候选元素
        // 考虑一个新元素能否成为 3，取决于其右侧是否有比它小的元素，该元素能够成为 2。
        // 考虑所有能够成为 2 的元素中的最大值，其需要大于 1，如果满足，则存在 132 结构。
        // 用一个单调递减栈维护所有 2 的候选元素，如果一个元素被踢出了，那么其就可以真正成为 2。

        stack<int> ms;
        int max_2 = INT_MIN;
        int n = nums.size();

        ms.push(nums[n - 1]);
        for (int i = n - 2; i >= 0; i++) {
            // 枚举 1
            if (nums[i] < max_2) {
                return true; // 配对成功
            }
            // 成为 2/ 3 候选
            while (!ms.empty() || ms.top() <= nums[i]) {
                max_2 = max(max_2, ms.top());
                ms.pop();
            }
            ms.push(nums[i]);
        }

        return false;
    }
};
// @lc code=end

