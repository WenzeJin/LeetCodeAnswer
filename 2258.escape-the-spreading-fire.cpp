/*
 * @lc app=leetcode.cn id=2258 lang=cpp
 *
 * [2258] Escape the Spreading Fire
 */

#include <vector>
#include <deque>

using namespace std;

// @lc code=start
class Solution {

    int DELTA[4][2] = {
        {0, 1}, {0, -1}, {1, 0}, {-1, 0}
    };

public:
    int maximumMinutes(vector<vector<int>>& grid) {
        // 首先想到能不能 dp，因为我们可以预先处理火到达每个位置的时间点，是否可以 dp 每个位置的最长停留时间？答案是不行，因为和最近距离不是一种问题，我们不知道上下左右哪个格子的最长停留时间最长。存在循环依赖。
        // 接着考虑枚举，枚举等待时间，由于达到最长等待时间之后，任何时间都不行，最长等待时间之前，任何时间都行，所以可以二分。

        auto check = [&](int stayTime) -> bool {
            // 检查是否能够待 stayTime, 即基于 bfs 模拟
            int m = grid.size();
            int n = grid[0].size();
            // grid[i][j]: 0 草，1 火， 2 墙
            // status[i][j]: 0 无事发生，1 走过，2 着火
            vector<vector<int>> status(m, vector<int>(n));
            // 先模拟 t 步火蔓延
            deque<pair<int, int>> fireQueue;
            int fireLayer = 0;  // 当前火层数量
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (grid[i][j] == 1) {
                        fireQueue.emplace_back(i, j);
                        status[i][j] = 2;
                        fireLayer++;
                    }
                }
            }

            for(int i = 0; i < stayTime && !fireQueue.empty(); i++) {
                int thisLayer = 0;
                for (int j = 0; j < fireLayer; j++) {
                    auto pos = fireQueue.front();
                    fireQueue.pop_front();
                    for (auto d: DELTA) {
                        int nextI = pos.first + d[0];
                        int nextJ = pos.second + d[1];
                        if (nextI >= 0 && nextI < m && nextJ >= 0 && nextJ < n) {
                            if (grid[nextI][nextJ] != 2 && status[nextI][nextJ] != 2) {
                                thisLayer++;
                                status[nextI][nextJ] = 2;
                                fireQueue.emplace_back(nextI, nextJ);
                            }
                        }
                    }
                }
                fireLayer = thisLayer;
            }

            if (status[0][0] == 2) {
                return false; // 已经着火
            }
            
            int walkLayer = 1;
            deque<pair<int, int>> walkQueue;
            walkQueue.emplace_back(0, 0);

            while (!walkQueue.empty()) {
                int thisWalkLayer = 0;
                int thisFireLayer = 0;
                // 人先走
                for (int i = 0; i < walkLayer; i++) {
                    auto pos = walkQueue.front();
                    walkQueue.pop_front();
                    if (pos.first == m - 1 && pos.second == n - 1) {
                        return true;    // 到达
                    }
                    if (status[pos.first][pos.second] == 2) {
                        continue;   // 已经着火，不能再走
                    }
                    for (auto d: DELTA) {
                        int nextI = pos.first + d[0];
                        int nextJ = pos.second + d[1];
                        if (nextI >= 0 && nextI < m && nextJ >= 0 && nextJ < n) {
                            if (grid[nextI][nextJ] != 2 && status[nextI][nextJ] == 0) {
                                thisWalkLayer++;
                                status[nextI][nextJ] = 1;
                                walkQueue.emplace_back(nextI, nextJ);
                            }
                        }
                    }
                }
                // 火蔓延
                for (int j = 0; j < fireLayer; j++) {
                    auto pos = fireQueue.front();
                    fireQueue.pop_front();
                    for (auto d: DELTA) {
                        int nextI = pos.first + d[0];
                        int nextJ = pos.second + d[1];
                        if (nextI >= 0 && nextI < m && nextJ >= 0 && nextJ < n) {
                            if (grid[nextI][nextJ] != 2 && status[nextI][nextJ] != 2) {
                                thisFireLayer++;
                                status[nextI][nextJ] = 2;
                                fireQueue.emplace_back(nextI, nextJ);
                            }
                        }
                    }
                }

                walkLayer = thisWalkLayer;
                fireLayer = thisFireLayer;
            }

            return false;
        };

        int m = grid.size(), n = grid[0].size();
        // invariant: l true r false;
        int l = 0;
        int r = m * n;

        if (check(r)) {
            return 1000000000;
        }
        if (!check(l)) {
            return -1;
        }

        while (l + 1 < r) {
            int mid = l + (r - l) / 2;
            mid = mid == l ? mid + 1 : mid;
            if (check(mid)) {
                l = mid;
            } else {
                r = mid;
            }
        }
        return l;
    }
};
// @lc code=end

