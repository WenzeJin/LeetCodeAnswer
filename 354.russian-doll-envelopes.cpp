/*
 * @lc app=leetcode.cn id=354 lang=cpp
 *
 * [354] Russian Doll Envelopes
 */

#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // 这也是一个典型的 LIS 问题，如何将二维转化为 LIS，就是如何进行排序：首先，从小到大按 w 排序，其次，同样的 w 内，h 按 从大到小排序，这样就能确保 同样的 w 在 LIS 中不会被二次使用（用 h 做 LIS）。
        
        sort(envelopes.begin(), envelopes.end(), [](auto& x, auto& y) -> bool {
            if (x[0] < y[0]) {
                return true;
            } else if (x[0] == y[0]) {
                return x[1] > y[1];
            } else {
                return false;
            }
        });

        vector<int> g;
        for (auto& e: envelopes) {
            int l = lower_bound(g.begin(), g.end(), e[1]) - g.begin() + 1;
            if (l > g.size()) {
                g.push_back(e[1]);
            } else {
                g[l - 1] = min(g[l - 1], e[1]);
            }
        }

        return g.size();

    }
};
// @lc code=end

