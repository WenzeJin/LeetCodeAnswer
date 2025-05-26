/*
 * @lc app=leetcode.cn id=1052 lang=cpp
 *
 * [1052] Grumpy Bookstore Owner
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        // 根据题意，grumpy = 1 时 顾客不满意，所以预处理不做任何事时顾客的满意数量
        // 接着用一个滑动窗口，找到放技能的最大增量
        // 用原有的满意数量加上这个最大增量

        int ori = 0;
        for (int i = 0; i < customers.size(); i++) {
            if (grumpy[i] == 0) {
                ori += customers[i];
            }
        }

        int window = 0;
        int maxDelta = INT_MIN;
        for (int i = 0; i < customers.size(); i++) {
            if (i < minutes) {
                // 窗口内是放技能后的增量
                window += grumpy[i] == 1 ? customers[i] : 0;
            } else {
                window -= grumpy[i - minutes] == 1 ? customers[i - minutes] : 0;
                window += grumpy[i] == 1 ? customers[i] : 0;
            }

            if (i >= minutes - 1) {
                maxDelta = max(window, maxDelta);
            }
        }

        return ori + maxDelta;
    }
};
// @lc code=end

