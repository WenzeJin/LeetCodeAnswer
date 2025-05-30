/*
 * @lc app=leetcode.cn id=3372 lang=cpp
 *
 * [3372] Maximize the Number of Target Nodes After Connecting Trees I
 */

#include <vector>

using namespace std;

// @lc code=start
/*
    这题非常绕，但是实际上用贪心就可以解决，如果要使 target 数量最多，那么对于连接边，第一棵树上肯定要选 i，第二棵树上只要选 k - 1 范围内点最多的点就可以了。
*/
class Solution {
    vector<vector<int>> buildGraph(vector<vector<int>>& edges) {
        vector<vector<int>> g(edges.size() + 1);
        for (auto& e: edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        return g;
    }

    int dfs(vector<vector<int>>& graph, vector<bool>& visited, int curr, int k) {
        visited[curr] = true;
        if (k < 0) {
            return 0;
        }
        if (k == 0) {
            return 1;
        }
        int res = 1;
        for (int out: graph[curr]) {
            if (!visited[out]) {
                res += dfs(graph, visited, out, k - 1);
            }
        }
        return res;
    }

public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        // deal with g2
        int max2 = 0;
        {
            auto g = buildGraph(edges2);
            
            for (int i = 0; i < edges2.size() + 1; i++) {
                vector<bool> visited(edges2.size() + 1);
                max2 = max(max2, dfs(g, visited, i, k - 1));
            }
        }
        // deal with g1
        vector<int> res(edges1.size() + 1);
        {
            auto g = buildGraph(edges1);
            for (int i = 0; i < edges1.size() + 1; i++) {
                vector<bool> visited(edges1.size() + 1);
                int cnt = dfs(g, visited, i, k);
                res[i] = cnt + max2;
            }
        }
        return res;
    }
};
// @lc code=end

