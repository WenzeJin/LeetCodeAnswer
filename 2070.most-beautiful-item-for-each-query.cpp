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

        vector<int> maxBeauty(items.size());
        maxBeauty[0] = items[0][1];
        for (int i = 1; i < items.size(); i++) {
            maxBeauty[i] = max(maxBeauty[i - 1], items[i][1]);
        }

        vector<int> res;
        res.reserve(queries.size());
        
        for (int query: queries) {
            // 二分查找 upper_bound
            int maxItem = upper_bound(items.begin(), items.end(), query, [](int query, const auto& item) {
                return query < item[0];
            }) - items.begin();
            int result = maxItem ? maxBeauty[maxItem - 1] : 0;
            res.push_back(result);
        }
        
        return res;
    }
};
// @lc code=end

