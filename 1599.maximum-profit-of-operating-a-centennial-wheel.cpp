/*
 * @lc app=leetcode.cn id=1599 lang=cpp
 *
 * [1599] Maximum Profit of Operating a Centennial Wheel
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
        // 每上一次客要转一次，过程中可能有一个盈利的最大值，在那时停止运转接客就可以了
        int profit = 0;
        int max_p = 0;
        int max_t = 0;
        int pending = 0;
        for (int i = 0; i < customers.size(); i++) {
            pending += customers[i];
            profit += min(4, pending) * boardingCost;
            profit -= runningCost;
            pending = max(0, pending - 4);
            if (profit > max_p) {
                max_t = i + 1;
                max_p = profit;
            }
        }

        return max_p == 0 ? -1: max_t;
    }
};
// @lc code=end

