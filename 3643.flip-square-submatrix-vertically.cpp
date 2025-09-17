/*
 * @lc app=leetcode.cn id=3643 lang=cpp
 *
 * [3643] Flip Square Submatrix Vertically
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        auto ans = grid;
        for (int i = 0; i < k / 2; i++) {
            auto& l1 = ans[x + i];
            auto& l2 = ans[x + k - i - 1];
            for (int j = y; j < y + k; j++) {
                swap(l1[j], l2[j]);
            }
        }
        return ans;
    }
};
// @lc code=end

