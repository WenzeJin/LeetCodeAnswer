/*
 * @lc app=leetcode.cn id=289 lang=cpp
 *
 * [289] Game of Life
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {

public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> new_b(n, vector<int>(m));

        vector<vector<int>> bias = {
            {0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}
        };

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int live = 0;
                for (auto& b: bias) {
                    int ni = i + b[0];
                    int nj = j + b[1];
                    if (0 <= ni && ni < n && 0 <= nj && nj < m) {
                        if (board[ni][nj]) {
                            live++;
                        }
                    } 
                }

                cout << i << " " << j << " " << live << endl;

                if (board[i][j]) {
                    if (live < 2 || live > 3) {
                        new_b[i][j] = 0;
                    } else {
                        new_b[i][j] = 1;
                    }
                } else {
                    if (live == 3) {
                        new_b[i][j] = 1;
                    }
                }
            }
        }

        swap(board, new_b);
    }
};
// @lc code=end

