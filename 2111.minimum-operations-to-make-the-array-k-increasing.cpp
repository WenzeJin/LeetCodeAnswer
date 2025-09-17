/*
 * @lc app=leetcode.cn id=2111 lang=cpp
 *
 * [2111] Minimum Operations to Make the Array K-Increasing
 */

#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    int kIncreasing(vector<int>& arr, int k) {
        // 由于我们可以任意修改其他数字，所以只要求每个 k 间隔序列上的 LIS 即可。
        int tot_lis = 0;
        for (int i = 0; i < k; i++) {
            vector<int> g;
            // 求 LIS
            for (int j = i; j < arr.size(); j += k) {
                auto it = upper_bound(g.begin(), g.end(), arr[j]);
                int l = it - g.begin() + 1;
                if (l > g.size()) {
                    g.push_back(arr[j]);
                } else {
                    g[l - 1] = arr[j];
                }
            }
            tot_lis += g.size();
        }

        return arr.size() - tot_lis;
    }
};
// @lc code=end

