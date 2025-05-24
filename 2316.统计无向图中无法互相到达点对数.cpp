/*
 * @lc app=leetcode.cn id=2316 lang=cpp
 *
 * [2316] 统计无向图中无法互相到达点对数
 */

#include <vector>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
    vector<vector<int>> g;
    vector<int> group;
    unordered_map<int, int> stats;

    void dfs(int curr, int g_no) {
        group[curr] = g_no;
        ++stats[g_no];
        for (int out: g[curr]) {
            if (group[out] == -1) {
                dfs(out, g_no);
            }
        }
    }

public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        g = vector<vector<int>>(n);
        group = vector<int>(n, -1);

        for (auto& e: edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        for (int i = 0; i < n; i++) {
            if (group[i] == -1) {
                dfs(i, i);
            }
        }

        int cnt = 0;
        long long sum = 0;

        // 以分组为单位，计算不可达点对，注意不要重复，所以这里用 cnt 记录我们已经遍历过的点数目 这样就可以在 O(n) 时间内统计
        for (auto& kv: stats) {
            long long in = kv.second;
            long long out = n - cnt - in;
            sum += in * out;
            cnt += in;
        }

        return sum;
    }
};
// @lc code=end

