/*
 * @lc app=leetcode.cn id=2070 lang=cpp
 *
 * [2070] Most Beautiful Item for Each Query
 */

#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end(), [](auto& x, auto& y) {
            return x[0] < y[0];
        });
        // 先根据 price 排序
        // 然后预先处理一下从头到目前的最大 beauty
        vector<int> maxBeauty(items.size());
        maxBeauty[0] = items[0][1];
        for (int i = 1; i < items.size(); i++) {
            maxBeauty[i] = max(maxBeauty[i - 1], items[0][1]);
        }
        
        // 二分查找 upper_bound
        auto maxItem = upper_bound(items.begin(), items.end(), )
    }
};
// @lc code=end

