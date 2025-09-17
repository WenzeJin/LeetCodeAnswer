/*
 * @lc app=leetcode.cn id=768 lang=cpp
 *
 * [768] Max Chunks To Make Sorted II
 */

#include <vector>
#include <stack>

using namespace std;

// @lc code=start
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        // 题目条件意味着块之间是有序的，及后方的块不能含有比前方块更小的元素，一旦遇到更小的元素，就意味着不能分块。
        // 当一个更小的元素来临时，如果其小于当前块最大值，则需要融合进当前块，如果仍然小于更前一个块的最大值，则需要将这两个块融合，直到找到一个块，其最大值小于等于该元素，用一个单调递增的栈存储每一个块的最大值。

        stack<int> ms;
        for (int x: arr) {
            if (ms.empty() || ms.top() <= x) {
                ms.push(x);
                continue;
            }
            int m = ms.top();
            while(!ms.empty() && ms.top() > x) {
                ms.pop();   // 将这些块融合
            }
            // 融合的新的块，最大值依然是 m
            ms.push(m);
        }

        return ms.size();
    }
};
// @lc code=end

