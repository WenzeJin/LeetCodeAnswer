/*
 * @lc app=leetcode.cn id=1584 lang=cpp
 *
 * [1584] Min Cost to Connect All Points
 */

#include <algorithm>
#include <vector>

using namespace std;

// @lc code=start
class UFSet {

    vector<int> buffer;

public:
    UFSet(int n): buffer(n, -1) {};

    int find(int x) {
        if (buffer[x] >= 0) {
            buffer[x] = find(buffer[x]);
        } else {
            return x;
        }
        return x;
    }

    void merge(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (buffer[px] < buffer[py]) {
            buffer[px] += buffer[py];
            buffer[py] = px;
        } else {
            buffer[py] += buffer[px];
            buffer[px] = py;
        }
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }
};

struct Edge {
    int p1;
    int p2;
    int l;
};

struct CmpEdge {
    bool operator()(const Edge& e1, const Edge& e2) const {
        return e1.l < e2.l;
    }
}

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        // MST 模版题
        int n = points.size();
        vector<Edge> edges;
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                auto& pi = points[i];
                auto& pj = points[j];
                int len = abs(pi[0] - pj[0]) + abs(pi[1] - pj[1]);
                edges.emplace_back(i, j, len);
            }
        }

        sort(edges.begin(), edges.end(), CmpEdge());

        UFSet uf(n);

        int ans = 0;
        int cnt = 0;
        for (auto& e: edges) {
            if (uf.same(e.p1, e.p2)) {
                continue;
            }
            ans += e.l;
            cnt ++;
            if (cnt == n - 1) {
                return ans;
            }
            uf.merge(e.p1, e.p2);
        }
        return ans;
    }
};
// @lc code=end

