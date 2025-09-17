/*
 * @lc app=leetcode.cn id=2171 lang=cpp
 *
 * [2171] Removing Minimum Number of Magic Beans
 */

#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        // 由于无法确定具体要调整到哪个数，所以需要枚举
        // 比目标小的，全部要清零，比目标大的，只能保留目标数量
        // 所以最终留下来的数量是 >= 目标数量 * 目标，减去的数量就是总数 - 留下数量，另留下数量最大即可，先排序方便枚举

        long long total = 0;
        for (int x: beans) {
            total += x;
        }

        sort(beans.begin(), beans.end());

        long long minVal = LLONG_MAX;
        for (int i = 0; i < beans.size(); i++) {
            long long remain = (long long)beans[i] * (beans.size() - i);
            minVal = min(minVal, total - remain);
        }

        return minVal;

    }
};
// @lc code=end

