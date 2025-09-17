/*
 * @lc app=leetcode.cn id=3604 lang=cpp
 *
 * [3604] Minimum Time to Reach Destination in Directed Graph
 */

#include <climits>
#include <vector>
#include <queue>

using namespace std;

struct Edge {
    int dest;
    int start;
    int end;
};

// @lc code=start
class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges) {
        // 可以用 dijkstra 算法，此时优先由到达时间早决定。
        vector<vector<Edge>> g(n);
        for (auto& e: edges) {
            g[e[0]].emplace_back(e[1], e[2], e[3]);
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

        vector<int> dist(n, INT_MAX);
        dist[0] = 0;
        pq.emplace(0, 0);

        while(!pq.empty()) {
            auto p = pq.top();
            if (p.first > dist[p.second]) {
                continue;
            }
            if (p.second == n - 1) {
                return p.first;
            }
            for (auto& e: g[p.second]) {
                int new_dist = max(e.start, p.second) + 1;
                if (new_dist - 1 <= e.end && new_dist < dist[e.dest]) {
                    dist[e.dest] = new_dist;
                    pq.emplace(new_dist, e.dest);
                }
            }
        }

        return dist[n - 1];
    }
};
// @lc code=end

