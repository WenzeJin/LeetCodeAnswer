/*
 * @lc app=leetcode.cn id=3195 lang=cpp
 *
 * [3195] Find the Minimum Area to Cover All Ones I
 */

#include <climits>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int min_x = INT_MAX, min_y = INT_MAX, max_x = 0, max_y = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j]) {
                    min_x = min(i, min_x);
                    max_x = max(i, max_x);
                    min_y = min(j, min_y);
                    max_y = max(j, max_y);
                }
            }
        }
        return (max_x - min_x + 1) * (max_y - min_y + 1);
    }
};
// @lc code=end

