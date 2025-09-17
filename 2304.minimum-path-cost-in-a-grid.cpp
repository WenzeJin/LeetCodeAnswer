/*
 * @lc app=leetcode.cn id=2304 lang=cpp
 *
 * [2304] Minimum Path Cost in a Grid
 */

#include <climits>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        // 二维 dp 即可，可以状态压缩。dp[i][j] 表示到 i j 包含 j 这一格 的最小代价。
        auto prev = new vector<int>(grid[0].begin(), grid[0].end());
        auto curr = new vector<int>(grid[0].size());

        for (int i = 1; i < grid.size(); i++) {
            for (int j = 0; i < prev->size(); j++) {
                int minCost = INT_MAX;
                for (int k = 0; k < prev->size(); k++) {
                    minCost = min(minCost, (*prev)[k] + moveCost[grid[i - 1][k]][grid[i][j]]);
                }
                (*curr)[j] = minCost + grid[i][j];
            }
            swap(prev, curr);
        }

        int minCost = INT_MAX;
        for (int i = 0; i < prev->size(); i++) {
            minCost = min(minCost, (*prev)[i]);
        }
        return minCost;

    }
};
// @lc code=end

