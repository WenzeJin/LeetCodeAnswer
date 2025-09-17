/*
 * @lc app=leetcode.cn id=2407 lang=cpp
 *
 * [2407] Longest Increasing Subsequence II
 */

#include <algorithm>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
    vector<int> max_t; // Segment Tree
    
    void modify(int o, int l, int r, int i, int val) {
        if (l == r) {
            max_t[o] = max(max_t[o], val);
            return;
        }
        int m = (l + r) / 2; // [l, m], [m + 1, r]
        if (i <= m) {
            modify(o * 2, l, m, i, val);
        } else {
            modify(o * 2 + 1, m + 1, r, i, val);
        }
        max_t[o] = max(max_t[o * 2], max_t[o * 2 + 1]);
    }

    int query(int o, int l, int r, int L, int R) {
        // L R 是查询范围
        if (L <= l && r <= R) {
            return max_t[o];
        }
        int m = (l + r)/ 2;
        int l_max = 0, r_max = 0;
        if (L <= m) {
            l_max = query(o * 2, l, m, L, R);
        }
        if (R > m) {
            r_max = query(o * 2 + 1, m + 1, r, L, R);
        }
        return max(l_max, r_max);
    }

public:
    int lengthOfLIS(vector<int>& nums, int k) {
        // 对于 LIS 的优化，通常可以用两种：
        // 基于 LIS 长度，对每个长度末尾最小值的二分查找
        // 基于 LIS 要求的值域（比如前一个元素的范围应该在 a - b 内），用线段树类似的数据结构加速查询和更新。
        // 本题可以使用第二种
        // f[i][j] 表示在使用前 i 个元素的情况下，末尾是 j 的最大长度，初始化为0，在查询时，j往往是一个区间，所以可以使用线段树，而 i 可以压缩。

        int n = nums.size();
        int u = *max_element(nums.begin(), nums.end());
        max_t.resize(4 * u);

        for (int x: nums) {
            if (x == 1) {
                modify(1, 1, u, 1, 1);
            } else {
                // 使用当前数字的情况下，更新线段树
                int res = 1 + query(1, 1, u, max(x - k, 1), x - 1);
                modify(1, 1, u, x, res);
            }
        }

        return max_t[1];
    }
};
// @lc code=end

