/*
 * @lc app=leetcode.cn id=2106 lang=cpp
 *
 * [2106] Maximum Fruits Harvested After at Most K Steps
 */

#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        // 处理前缀和，方便直接获取总和
        vector<int> sum(fruits.size() + 1);
        for (int i = 1; i <= fruits.size(); i++) {
            sum[i] = sum[i - 1] + fruits[i - 1][1];
        }

        int maxVal = 0;

        // 枚举走 i 步之后折返的情况
        for (int i = 0; i <= k; i++) {
            // 先向右走 i 步
            int right, left, ub, lb;
            right = i + startPos;
            left = min(startPos, right - k + i);
            lb = lower_bound(fruits.begin(), fruits.end(), left, [](const auto& a, int b) {
                return a[0] < b;
            }) - fruits.begin();
            ub = upper_bound(fruits.begin(), fruits.end(), right, [](int b, const auto& a) { 
                return b < a[0]; 
            }) - fruits.begin();
            maxVal = max(maxVal, sum[ub] - sum[lb]);
            // 再向左走 i 步
            left = startPos - i;
            right = max(startPos, left + k - i);
            lb = lower_bound(fruits.begin(), fruits.end(), left, [](const auto& a, int b) {
                return a[0] < b;
            }) - fruits.begin();
            ub = upper_bound(fruits.begin(), fruits.end(), right, [](int b, const auto& a) { 
                return b < a[0]; 
            }) - fruits.begin();
            maxVal = max(maxVal, sum[ub] - sum[lb]);
        }
        return maxVal;
    }
};
// @lc code=end

