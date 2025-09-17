/*
 * @lc app=leetcode.cn id=3123 lang=cpp
 *
 * [3123] Find Edges in Shortest Paths
 */

#include <functional>
#include <vector>
#include <queue>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        for (int i = 0; i < edges.size(); i++) {
            g[edges[i][0]].push_back(i);
            g[edges[i][1]].push_back(i);
        }

        vector<long long> dist(n, -1);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.emplace(0, 0);

        long long d = LLONG_MAX;
        while (!pq.empty()) {
            auto f = pq.top();
            pq.pop();
            if (dist[f.second] != -1) {
                continue;
            }
            dist[f.second] = f.first;
            if (f.second == n - 1) {
                d = f.first;
                break;
            }
            for (auto oe: g[f.second]) {
                int o = edges[oe][0] == f.second ? edges[oe][1] : edges[oe][0];
                pq.emplace(f.first + edges[oe][2], o);
            }
        }

        vector<bool> res(edges.size());
        vector<bool> vis(n);
        function<bool(int, int)> dfs = [&](int curr, int length) -> bool {
            if (curr == n - 1) {
                return length == d;
            }

            if (length >= d) {
                return false;
            }


            bool flag = false;
            for (int oe: g[curr]) {
                int o = edges[oe][0] == curr ? edges[oe][1] : edges[oe][0];
                if (!vis[o]) {
                    vis[o] = true;
                    if (dfs(o, length + edges[oe][2])) {
                        res[oe] = true;
                        flag = true;
                    }
                    vis[o] = false;
                }
            }

            return flag;
        };

        vis[0] = true;
        dfs(0, 0);

        return res;
    }
};
// @lc code=end

