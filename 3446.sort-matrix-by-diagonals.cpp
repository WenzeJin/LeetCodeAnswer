/*
 * @lc app=leetcode.cn id=3446 lang=cpp
 *
 * [3446] Sort Matrix by Diagonals
 */

#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> ans(n, vector<int>(n));

        vector<int> buffer;
        // 左下对角线
        for (int i = 0; i < n; i++) {
            buffer.resize(n - i);

            for (int j = 0; j < n - i; j++) {
                buffer[j] = grid[i + j][j];
            }

            sort(buffer.begin(), buffer.end(), greater<>());

            for (int j = 0; j < n - i; j++) {
                ans[i + j][j] = buffer[j];
            }
        }
        // 又上对角线
        for (int i = 1; i < n; i++) {
            buffer.resize(n - i);

            for (int j = 0; j < n - i; j++) {
                buffer[j] = grid[j][i + j];
            }

            sort(buffer.begin(), buffer.end());

            for (int j = 0; j < n - i; j++) {
                ans[j][i + j] = buffer[j];
            }
        }

        return ans;
    }
};
// @lc code=end

