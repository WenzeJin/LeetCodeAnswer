/*
 * @lc app=leetcode.cn id=1793 lang=cpp
 *
 * [1793] Maximum Score of a Good Subarray
 */

#include <vector>
#include <stack>

using namespace std;

// @lc code=start
class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        // 由于数组的分数受到最小数限制，实际上是一个矩形面积问题，对于数组上的 nums[i]，如果用它作为矩形的高的话，需要找到左侧和右侧分别第一个小于 nums[i] 的下标。
        // 最终，这个矩形还应该囊括 k

        int n = nums.size();
        vector<int> ll(n), rl(n);
        stack<int> ms;

        ms.push(-1);
        for (int i = 0; i < n; i++) {
            while (ms.top() != -1 && nums[ms.top()] >= nums[i]) {
                ms.pop();
            }
            ll[i] = ms.top();
            ms.push(i);
        }

        ms = stack<int>();
        ms.push(n);
        for (int j = n - 1; j>= 0; j--) {
            while (ms.top() != n && nums[ms.top()] >= nums[j]) {
                ms.pop();
            }
            rl[j] = ms.top();
            ms.push(j);
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            if (ll[i] < k && k < rl[i]) {
                res = max(res, nums[i] * (rl[i] - ll[i] - 1));
            }
        }
        return res;
    }
};
// @lc code=end

