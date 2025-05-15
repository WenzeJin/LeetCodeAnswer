/*
 * @lc app=leetcode.cn id=354 lang=cpp
 *
 * [354] 俄罗斯套娃信封问题
 */

// @lc code=start
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;


int lengthOfLIS(vector<int>& arr) {
    /*
    基于二分查找的动态规划

    设 f[j] 表示 h 的前 i 个元素可以组成的长度为 j 的最长严格递增子序列的末尾元素的最小值，如果不存在长度为 j 的最长严格递增子序列，对应的 f 值无定义。在定义范围内，可以看出 f 值是严格单调递增的，因为越长的子序列的末尾元素显然越大。

    所以，我们整体的思想就是，设计一个数组f，在扫描的过程中，尽可能压缩每一项的大小，实在不行再往后增加一项，这样可以腾出更大的空间构建序列，比如 [1, 3, 4] 和 [1, 2, 3] 显然后者更有可能构造出更长的序列。

    转移方程是，如果 arr[k] 大于 f[1..i], 则 f[i + 1] = arr[k]
    否则找到一个最大的严格小于 arr[k] 的 f[i] f[i+1] = arr[k]

    */

    vector<int> top(arr.size());

    int piles = 0;
    for (int x: arr) {
        auto pos = lower_bound(top.begin(), top.begin() + piles, x);
        if (pos == top.begin() + piles) {
            top[piles] = x;
            piles++;
        } else {
            *pos = x;
        }
    }
    return piles;
}

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {

        sort(envelopes.begin(), envelopes.end(), [](vector<int> &x, vector<int> &y) -> bool { 
            if (x[0] < y[0]) {
                return true;
            } else if (x[0] == y[0]) {
                return x[1] > y[1];
            }
            return false;
        });
        // 我们对第二维进行倒序排列，是为了确保对第二维在应用LIS时，不会有相同的第一维被选中，如果允许有相同的第一维或第二维，那么第二维正序排列

        vector<int> height;

        for (auto& env: envelopes) {
            height.push_back(env[1]);
        }

        return lengthOfLIS(height);
    }
};
// @lc code=end

