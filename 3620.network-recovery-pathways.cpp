/*
 * @lc app=leetcode.cn id=3620 lang=cpp
 *
 * [3620] Network Recovery Pathways
 */

#include <climits>
#include <vector>
#include <queue>

using namespace std;

// @lc code=start
class Solution {
    vector<vector<pair<int, int>>> g;
    vector<int> deg;
    int n = 0;
    long long K;
    
    bool check(int limit, vector<bool>& online) {
        // 用 DP 确认在 limit 下，前往终点的最短路径
        vector<int> temp(deg);
        queue<int> q;
        vector<long long> dist(n, LLONG_MAX);
        for (int i = 0; i < n; i++) {
            if (temp[i] == 0) {
                q.push(i);
            }
        }
        dist[0] = 0;

        while (!q.empty()) {
            int i = q.front();
            q.pop();
            for (auto oe: g[i]) {
                temp[oe.first]--;
                if (dist[i] <= K && online[i] && oe.second >= limit) {
                    dist[oe.first] = min(dist[oe.first], dist[i] + oe.second);
                }
                if (temp[oe.first] == 0) {
                    q.push(oe.first);
                }
            }
        }

        return dist[n - 1] <= K;
    }

    

public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        n = online.size();
        K = k;
        // 直接做不是很好做，因为我们没法一边 DP，一边判断所有路径长度和是否小于 k
        // 所以使用二分查找，这种最大化最小值的题很适合二分查找答案。我们限制路径上使用边的最小值，那么大于一个阈值之后，终点将无法到达。
        g.resize(n);
        deg.resize(n);
        int l = 0, r = 0;
        for (auto& e: edges) {
            g[e[0]].emplace_back(e[1], e[2]);
            deg[e[1]]++;
            r = max(r, e[2]);
        }
        // 保证 l 可行
        if (!check(0, online)) {
            return -1;
        }
        while (l < r) {
            int m = l + 1 + (r - l) / 2;
            if (check(m, online)) {
                l = m;
            } else {
                r = m - 1;
            }
        }
        return l;
    }
};
// @lc code=end

