/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
 */

#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // O(m + n) 做法：用一个单调栈从右向左遍历 nums2, 记录每个元素右侧第一个比它大的位置，做成 哈希表，对于nums1 中每个元素直接查询

        stack<int> ms;
        unordered_map<int, int> nextBig;

        for (int i = nums2.size() - 1; i >= 0; i --) {
            while (!ms.empty() && ms.top() <= nums2[i]) {
                ms.pop();
            }
            
            if (ms.empty()) {
                nextBig[nums2[i]] = -1;
            } else {
                nextBig[nums2[i]] = ms.top();  
            }

            ms.push(nums2[i]);
        }

        vector<int> res;
        for (int x: nums1) {
            res.push_back(nextBig[x]);
        }
        return res;
    }
};
// @lc code=end

