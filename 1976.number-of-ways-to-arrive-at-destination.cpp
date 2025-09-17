/*
 * @lc app=leetcode.cn id=1976 lang=cpp
 *
 * [1976] Number of Ways to Arrive at Destination
 */

#include <vector>
#include <queue>

using namespace std;

// @lc code=start
struct Edge {
    int dest;
    int len;
};

constexpr int MOD = 1e9 + 7;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // 要求最短路径数量，在 dijkstra上修改，如果一个点u可以刷新v，则 ways[v] = ways[u]，如果相等，则 ways[v] += ways[u]
        vector<vector<Edge>> g(n);
        for (auto& r: roads) {
            g[r[0]].emplace_back(r[1], r[2]);
            g[r[1]].emplace_back(r[0], r[2]);
        }

        int limit = INT_MAX;
        vector<int> dist(n, INT_MAX);
        vector<int> ways(n);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; // len, dest
        dist[0] = 0;
        ways[0] = 1;
        pq.emplace(0, 0);

        while (!pq.empty()) {
            auto p = pq.top();
            pq.pop();

            if (p.first > dist[p.second]) {
                // 过时了
                continue;
            }
            if (p.first == dist[p.second] && p.second != 0) {
                continue;
            }

            dist[p.second] = p.first;

            for (auto& e: g[p.second]) {
                if (p.first + e.len < dist[e.dest]) {
                    dist[e.dest] = p.first + e.len;
                    ways[e.dest] = ways[p.second];
                    pq.emplace(dist[e.dest], e.dest);
                } else if (p.first + e.len == dist[e.dest]) {
                    ways[e.dest] += ways[p.second];
                    ways[e.dest] %= MOD;
                }
            }
        }

        return ways[n - 1];
    }
};
// @lc code=end

