/*
 * @lc app=leetcode.cn id=1971 lang=cpp
 *
 * [1971] 寻找图中是否存在路径
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
    int dest;
    vector<bool> visited;
    vector<vector<int>> g;
public:
    bool dfs(int curr) {
        visited[curr] = true;
        if (curr == dest) {
            return true;
        }

        for (int out: g[curr]) {
            if (!visited[out]) {
                if (dfs(out)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        visited = vector<bool>(n);
        g = vector<vector<int>>(n);
        dest = destination;

        for (auto& e: edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        return dfs(source);
    }
};
// @lc code=end

