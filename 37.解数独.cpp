/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */

#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;

// @lc code=start
typedef vector<vector<char>> Board;


class Solution {
    vector<unordered_set<char>> row_char;
    vector<unordered_set<char>> col_char;
    vector<unordered_set<char>> box_char;

public:
    bool dfs(Board& board, int row, int col) {
        if (col == 9) {
            if (row == 8) {
                return true;
            }
            return dfs(board, row + 1, 0);
        }

        if (board[row][col] != '.') {
            return dfs(board, row, col + 1);
        }

        for (int i = 1; i <= 9; i++) {
            char c = '0' + i;
            // cout << row << " " << col << " " << c << endl;
            if (row_char[row].find(c) != row_char[row].end() 
            || col_char[col].find(c) != col_char[col].end() 
            || box_char[getBox(row, col)].find(c) != box_char[getBox(row,col)].end()) {
                continue;
            }
            row_char[row].insert(c);
            col_char[col].insert(c);
            box_char[getBox(row, col)].insert(c);
            board[row][col] = c;
            if (dfs(board, row, col + 1)) {
                return true;
            }
            row_char[row].erase(c);
            col_char[col].erase(c);
            box_char[getBox(row, col)].erase(c);
            board[row][col] = '.';
        }

        return false;
    }

    int getBox(int i, int j) {
        return (i / 3) * 3 + j / 3; 
    }

    void solveSudoku(vector<vector<char>>& board) {
        row_char = vector<unordered_set<char>>(9);
        col_char = vector<unordered_set<char>>(9);
        box_char = vector<unordered_set<char>>(9);
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                row_char[i].insert(board[i][j]);
                col_char[j].insert(board[i][j]);
                box_char[getBox(i, j)].insert(board[i][j]);
            }
        }


        dfs(board, 0, 0);
    }
};
// @lc code=end

