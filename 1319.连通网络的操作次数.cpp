/*
 * @lc app=leetcode.cn id=1319 lang=cpp
 *
 * [1319] 连通网络的操作次数
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
    vector<bool> visited;
    vector<vector<int>> g;

    void dfs(int curr) {
        visited[curr] = true;
        for (int out: g[curr]) {
            if (!visited[out]) {
                dfs(out);
            }
        }
    }

public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        // 根据结论，连通图最少有 n - 1 条边，所以少于这个数目的就是不可能，多余这个数目的肯定可能
        // 题目只要求次数，所以只要求不连通区块的个数 - 1就可以了，因为我们不用管到底是拔哪根线，总有线可以拔
        if (connections.size() < n - 1) {
            return -1;
        }

        visited = vector<bool>(n);
        g = vector<vector<int>>(n);

        for (auto& e: connections) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        int groups = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                groups++;
                dfs(i);
            }
        }

        return groups - 1;
    }
};
// @lc code=end

