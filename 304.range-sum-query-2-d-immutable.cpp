/*
 * @lc app=leetcode.cn id=304 lang=cpp
 *
 * [304] Range Sum Query 2D - Immutable
 */

#include <vector>

using namespace std;

// @lc code=start
class NumMatrix {
    vector<vector<int>> subSum;

public:
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        subSum = vector<vector<int>>(n + 1, vector<int>(m + 1));
        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                subSum[i][j] = matrix[i][j] + subSum[i + 1][j] + subSum[i][j + 1] - subSum[i + 1][j + 1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return subSum[row1][col1] - subSum[row2 + 1][col1] - subSum[row1][col2 + 1] + subSum[row2 + 1][col2 + 1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end

