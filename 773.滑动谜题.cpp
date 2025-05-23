/*
 * @lc app=leetcode.cn id=773 lang=cpp
 *
 * [773] 滑动谜题
 */

#include <vector>
#include <deque>
#include <unordered_set>
#include <iostream>

using namespace std;

// @lc code=start

typedef vector<vector<int>> Board;

struct HashBoard {
    size_t operator () (const Board& board) const {
        size_t res = 0;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                res ^= std::hash<int>{}(i) + 0x9e3779b9;
            }
        }
        return res;
    }
};

class Solution {
public:
    bool check(Board& board) {
        return board[0][0] == 1 
            && board[0][1] == 2
            && board[0][2] == 3
            && board[1][0] == 4
            && board[1][1] == 5
            && board[1][2] == 0;
    }

    int slidingPuzzle(Board& board) {
        int move = 0;
        vector<vector<int>> delta = {
            {0, 1}, {1, 0}, {0, -1}, {-1, 0}
        };
        deque<Board> queue;
        unordered_set<Board, HashBoard> visited;
        queue.push_back(board);
        while(!queue.empty()) {
            deque<Board> temp = std::move(queue);
            queue = deque<Board>();
            for (auto& b: temp) {
                if (check(b)) {
                    return move;
                }

                int i, j; bool flag = false;
                for (i = 0; i < 2; i++) {
                    for(j = 0; j < 3; j++) {
                        if (b[i][j] == 0) {
                            flag = true;
                            break;
                        }
                    }
                    if (flag) {
                        break;
                    }
                }


                // swap any number around i, j
                for (auto& d: delta) {
                    int ni = i + d[0], nj = j + d[1];
                    
                    if (ni < 0 || ni >= 2 || nj < 0 || nj >= 3) {
                        continue;
                    }

                    auto nb = b;
                    swap(nb[i][j], nb[ni][nj]);
                    if (visited.find(nb) == visited.end()) {
                        visited.insert(nb);
                        queue.push_back(nb);
                    }
                }
            }
            ++move;
        }
        return -1;
    }
};
// @lc code=end

