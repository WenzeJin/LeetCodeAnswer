/*
 * @lc app=leetcode.cn id=909 lang=cpp
 *
 * [909] Snakes and Ladders
 */

#include <vector>
#include <queue>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        vector<int> lineBoard;
        lineBoard.reserve(board.size() * board.size());
        bool direct = true;
        int n = board.size();
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                if (direct)
                    lineBoard.push_back(board[i][j]);
                else
                    lineBoard.push_back(board[i][n - j - 1]);
            }
            direct = !direct;
        }

        // for (int i: lineBoard) {
        //     cout << i << " ";
        // }
        // cout << endl;

        // use bfs for min moves
        int move = 0;
        auto next = new queue<int>;
        auto prev = new queue<int>;
        vector<bool> visited(lineBoard.size());
        next->push(1);
        while (!next->empty()) {
            swap(prev, next);
            while (!prev->empty()) {
                int ori = prev->front();
                prev->pop();
                if (ori == n * n) {
                    delete next;
                    delete prev;
                    return move;
                }
                for (int i = 1; i <= 6; i++) {
                    if (ori + i > n * n) {
                        break;
                    }
                    int opt = lineBoard[ori + i - 1];
                    if (opt != -1 && !visited[opt - 1]) {
                        next->push(opt);
                        visited[opt - 1] = true;
                    } else if (!visited[ori + i - 1]) {
                        next->push(ori + i);
                        visited[ori + i - 1] = true;
                    }
                }
            }
            ++move;
        }


        delete next;
        delete prev;
        return -1;
    }
};
// @lc code=end

