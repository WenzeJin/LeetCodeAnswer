/*
 * @lc app=leetcode.cn id=3638 lang=cpp
 *
 * [3638] Maximum Balanced Shipments
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {
        // 由于题目要求的是平衡装运的最大数量，所以只要每次选取两个元素进行装运就可以了。假设有一个最大组合，其中有一组大于两个元素，那么可以将这一组缩减到两个，总数不变。

        int cnt = 0;
        int i = 0;
        while (i < weight.size() - 1) {
            if (weight[i] > weight[i + 1]) {
                cnt++;
                i += 2;
            } else {
                i++;
            }
        }
        return cnt;
    }
};
// @lc code=end

