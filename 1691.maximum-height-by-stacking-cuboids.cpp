/*
 * @lc app=leetcode.cn id=1691 lang=cpp
 *
 * [1691] Maximum Height by Stacking Cuboids 
 */

#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
    // vector<int> max_h;

    // void update(int o, int l, int r, int i, int val) {
    //     if (l == r) {
    //         max_h[o] = max(max_h[o], val);
    //         return;
    //     }
    //     int m = (l + r) / 2;
    //     if (i <= m) {
    //         update(o * 2, l, m, i, val);
    //     } else {
    //         update(o * 2 + 1, m + 1, r, i, val);
    //     }
    //     max_h[o] = max(max_h[o * 2], max_h[o * 2 + 1]);
    // }

    // int query(int o, int l, int r, int L, int R) {
    //     if (L <= l && r <= R) {
    //         return max_h[o];
    //     }
    //     int l_max = 0, r_max = 0;
    //     int m = (l + r) / 2;
    //     if (L <= m) {
    //         l_max = query(o * 2, l, m, L, R);
    //     }
    //     if (R > m) {
    //         r_max = query(o * 2 + 1, m + 1, r, L, R);
    //     }
    //     return max(l_max, r_max);
    // }

public:
    int maxHeight(vector<vector<int>>& cuboids) {
        // 这是一个三维的 LIS 问题，如何转化为一维，首先按照 w 排序，在同样的 w 下按照 l 排序，在同样的l 下按照 h 排序，最后找 h 的 LIS 即可。
        // 同时，方块还可以翻转，所以，长宽高中，最长的放在高上，按序排列，这样可以最大化堆叠次数和高度（排序规避田忌赛马情况，达到最大堆叠次数，将高作为最大的最大化堆叠高度）。

        for (auto& c: cuboids) {
            sort(c.begin(), c.end());
        }

        sort(cuboids.begin(), cuboids.end(), [](auto& x, auto& y) {
            if (x[0] < y[0]) {
                return true;
            } else if (x[0] == y[0]) {
                if (x[1] < y[1]) {
                    return true;
                } else if (x[1] == y[1]) {
                    return x[2] < y[2];
                } else {
                    return false;
                }
            } else {
                return false;
            }
        });

        int n = cuboids.size();
        vector<int> dp(n);

        for (int i = 0; i < n; i++) {
            dp[i] = cuboids[i][2];
            for (int j = 0; j < i; j++) {
                if (cuboids[j][1] <= cuboids[i][1] && cuboids[j][2] <= cuboids[i][2]) {
                    dp[i] = max(dp[i], dp[j] + cuboids[i][2]);
                }
            }
        }

        return *max_element(dp.begin(), dp.end());
        
    }
};
// @lc code=end

