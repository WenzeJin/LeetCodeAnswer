/*
 * @lc app=leetcode.cn id=1187 lang=cpp
 *
 * [1187] Make Array Strictly Increasing
 */

#include <algorithm>
#include <climits>
#include <vector>
#include <unordered_map>
#include <functional>

using namespace std;

// @lc code=start
class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        // 可以枚举是否替换，如果选择将第 i 位替换，肯定是选择尽可能大的数 x 去替换（从后往前考虑的话），那么问题转换为，前 i - 1 位，严格递增并且末尾小于 x。可以使用记忆华搜索。
        sort(arr2.begin(), arr2.end());
        int n = arr1.size();
        vector<unordered_map<int, int>> memo(n);

        function<int(int,int)> dfs = [&](int i, int pre) -> int {
            if (i < 0) {
                return 0;
            }
            auto it = memo[i].find(pre);
            if (it != memo[i].end()) {
                return it->second;
            }
            // 不替换 a[i]
            int res = arr1[i] < pre ? dfs(i - 1, arr1[i]) : INT_MAX / 2; // 防止溢出
            // 替换 a[i] 找到小于 pre 最大的替换
            auto k = lower_bound(arr2.begin(), arr2.end(), pre);
            if (k != arr2.begin()) {
                res = min(res, dfs(i - 1, *(--k)) + 1);
            }
            return res;
        };

        int res = dfs(n - 1, INT_MAX);
        return res < INT_MAX / 2 ? res : -1;
        
    }
};
// @lc code=end

