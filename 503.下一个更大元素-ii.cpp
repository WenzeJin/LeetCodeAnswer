/*
 * @lc app=leetcode.cn id=503 lang=cpp
 *
 * [503] 下一个更大元素 II
 */

#include <vector>
#include <stack>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        // 两圈之内肯定能找到下一个更大元素
        stack<int> ms;
        vector<int> nextBig(nums.size(), -1);
        int sz = nums.size();
        for (int i = 0; i < sz * 2; i++) {
            while (!ms.empty() && nums[ms.top()] < nums[i % sz]) {
                nextBig[ms.top()] = nums[i % sz];
                ms.pop();
            }

            if (nextBig[i % sz] == -1) {
                ms.push(i % sz);
            }
        }
        return nextBig;
    }
};
// @lc code=end

