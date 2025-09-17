/*
 * @lc app=leetcode.cn id=2328 lang=cpp
 *
 * [2328] Number of Increasing Paths in a Grid
 */

#include <vector>

using namespace std;

// @lc code=start
#define MOD 1000000007

struct Node {
    bool visited = false;
    int routes = 0;
    vector<Node *> children;
};

class Solution {
public:
    void dfs(Node &node) {
        // 计算以 node 为起点的路径数量
        if (node.visited) {
            return;
        }

        int routes = 1; // 肯定有一个
        for (auto out: node.children) {
            if (!out->visited) {
                dfs(*out);
            } 
            routes += out->routes;
            routes %= MOD;
        }

        node.routes = routes;
        node.visited = true;
    }

    int countPaths(vector<vector<int>>& grid) {
        // 可以利用大小关系，为图上所有格点，建立一个 DAG，求 DAG 上路径数目就可以了。
        int delta[4][2] = {
            {0, 1}, {1, 0}, {0, -1}, {-1, 0}
        };

        int n = grid.size();
        int m = grid[0].size();
        vector<vector<Node>> dp(n, vector<Node>(m));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (auto d: delta) {
                    int ni = i + d[0];
                    int nj = j + d[1];
                    if (ni < n && ni >= 0 && nj < m && nj >= 0) {
                        if (grid[i][j] < grid[ni][nj]) {
                            dp[i][j].children.push_back(&dp[ni][nj]);
                        }
                    }
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!dp[i][j].visited) {
                    dfs(dp[i][j]);
                }
                ans += dp[i][j].routes;
                ans %= MOD;
            }
        }

        return ans;
    }
};
// @lc code=end

