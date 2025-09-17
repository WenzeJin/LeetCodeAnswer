/*
 * @lc app=leetcode.cn id=2866 lang=cpp
 *
 * [2866] Beautiful Towers II
 */

#include <vector>
#include <stack>

using namespace std;

// @lc code=start
class Solution {
public:
    long long maximumSumOfHeights(vector<int>& maxHeights) {
        // 分别从前至后和从后之前开始建不严格递增高度，看看到 i 为止，总和最多能多高。用一个单调递增栈维护i前方第一个高度限制比 i 小的位置。
        int n = maxHeights.size();
        stack<int> ms;
        vector<long long> pre(n);
        vector<long long> post(n);
        
        ms.push(-1);
        for (int i = 0; i < n; i++) {
            while (ms.top() != -1 && maxHeights[ms.top()] >= maxHeights[i]) {
                ms.pop();
            }
            long long max_h = (long long)maxHeights[i] * (i - ms.top());
            if (ms.top() != -1) {
                max_h += pre[ms.top()];
            }
            ms.push(i);
            pre[i] = max_h;
        }
        ms = stack<int>();
        ms.push(n);
        for (int i = n - 1; i >= 0; i--) {
            while (ms.top() != n && maxHeights[ms.top()] >= maxHeights[i]) {
                ms.pop();
            }
            long long max_h = (long long)maxHeights[i] * (ms.top() - i);
            if (ms.top() != n) {
                max_h += post[ms.top()];
            }
            ms.push(i);
            post[i] = max_h;
        }
        long long res = 0;
        for (int i = 0; i < n; i++) {
            res = max(res, pre[i] + post[i] - maxHeights[i]);
        }
        return res;
    }
};
// @lc code=end

