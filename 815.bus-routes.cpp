/*
 * @lc app=leetcode.cn id=815 lang=cpp
 *
 * [815] Bus Routes
 */

#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using namespace std;

// @lc code=start
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        // 不能直接建图，建图需要 n2 时间
        // 用另一种方式 On 建图，略微增加查询时间
        unordered_map<int, unordered_set<int>> pos2routes;

        for (int i = 0; i < routes.size(); i++) {
            for (int j = 0; j < routes[i].size(); j++) {
                pos2routes[routes[i][j]].insert(i);
            }
        }

        unordered_set<int> visited;
        unordered_set<int> routeUsed;
        queue<pair<int, int>> q; // [curr, move]
        visited.insert(source);
        q.emplace(source, 0);
        while (!q.empty()) {
            auto [curr, move] = q.front();
            q.pop();
            if (curr == target) {
                return move;
            }
            for (int i: pos2routes[curr]) {
                if (!routeUsed.count(i)) {
                    // 可以显著降低时间复杂度，因为我们最近的路线不可能坐两次同样的车，如果不做这个优化，还是 On2的，只是将建图时的时间延迟到了遍历时
                    routeUsed.insert(i);
                    for (int x: routes[i]) {
                        if (!visited.count(x)) {
                            visited.insert(x);
                            q.emplace(x, move + 1);
                        }
                    }
                }
            }
        }


        return -1;
    }
};
// @lc code=end

