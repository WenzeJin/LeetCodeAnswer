/*
 * @lc app=leetcode.cn id=2929 lang=cpp
 *
 * [2929] Distribute Candies Among Children II
 */

#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    long long distributeCandies(int n, int limit) {
        // 可以想像成分配“空位”，共 3 * limit - n 个空位，如果空位 < 0 则无法分配
        // 分配空位可以使用数学上的插板法，两个板可以位于同一个间隔中，也可以位于不同间隔中，分类讨论。
        // 板之间的间隔不能超过 limit 
        int space = 3 * limit - n;
        if (space < 0) {
            return 0;
        }
        if (space == 0) {
            return 1;
        }

        int res = 0;
        for (int i = 0; i < space + 1; i++) {
            // 第二块板最多可以插到 i + limit 的位置
            int secondMax = min(i + limit, space);
            // 第二块板至少要插到 space - limit 的位置
            int secondMin = max(i, space - limit);
            res += max(0, secondMax - secondMin);
        }
        return res;
    }
};
// @lc code=end

