/*
 * @lc app=leetcode.cn id=1301 lang=cpp
 *
 * [1301] Number of Paths with Max Score
 */

#include <vector>

using namespace std;

#define MOD 1000000007

// @lc code=start
class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        // 每个格子的最大的分路径无非就是从下方，右下方，右边的最大的分而来，而方案数，就是能够产生最大得分路径的总和。
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> max_score(n + 1, vector<int>(m + 1));
        vector<vector<long long>> routes(n + 1, vector<long long>(m + 1));
        routes[n - 1][m - 1] = 1;

        int bias[3][2] = {
            {0, 1}, {1, 0}, {1, 1}
        };
        
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (i == n - 1 && j == m - 1) {
                    continue;
                }
                if (board[i][j] == 'X') {
                    routes[i][j] = 0;
                    max_score[i][j] = 0;
                    continue;
                }
                int max_s = 0;
                for (auto b: bias) {
                    if (max_score[i + b[0]][j + b[1]] > max_s) {
                        max_s = max_score[i + b[0]][j + b[1]];
                        routes[i][j] = routes[i + b[0]][j + b[1]];
                    } else if (max_score[i + b[0]][j + b[1]] == max_s) {
                        routes[i][j] += routes[i + b[0]][j + b[1]];
                        routes[i][j] %= MOD;
                    }
                }
                if (board[i][j] == 'E') {
                    max_score[i][j] = max_s;
                } else {
                    max_score[i][j] = max_s + board[i][j] - '0';
                }
            }
        }

        if (routes[0][0] == 0) {
            return {0, 0};
        } else {
            return {max_score[0][0] , int(routes[0][0] % MOD)};
        }
    }
};
// @lc code=end

