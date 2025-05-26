/*
 * @lc app=leetcode.cn id=1857 lang=cpp
 *
 * [1857] Largest Color Value in a Directed Graph
 */

#include <vector>
#include <string>

using namespace std;

// @lc code=start

/*
    本题使用DAG 上的 DP 就可以完成任务，因为颜色有上限 26，所以DAG DP 若用 dp[i][c] 表示节点 i 的所有路径中颜色c出现次数最多的次数，那么就可以在 O(26n) = O(n) 的时间内解决问题
 */
class Solution {
    vector<vector<int>> g;
    vector<vector<int>> dp;
    vector<int> visited;
    int maxVal;

    bool dfs(string& colors, int curr) {
        visited[curr] = 1; // visiting
        dp[curr][colors[curr] - 'a'] = 1;
        for (int out: g[curr]) {
            if (visited[out] == 1) {
                return false; // there is a loop
            }
            if (visited[out] == 0) {
                if (!dfs(colors, out)) {
                    return false;
                }
            }
            for (int i = 0; i < 26; i++) {
                if (colors[curr] == 'a' + i) {
                    dp[curr][i] = max(dp[curr][i], dp[out][i] + 1);
                } else {
                    dp[curr][i] = max(dp[curr][i], dp[out][i]);
                }
            }
        }
        for (int i = 0; i < 26; i++) {
            maxVal = max(maxVal, dp[curr][i]);
        }
        visited[curr] = 2; // visited
        return true;
    }

public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.length();
        maxVal = 0;
        dp = vector<vector<int>>(n, vector<int>(26));
        g = vector<vector<int>>(n);
        visited = vector<int>(n);

        for (auto& e: edges) {
            g[e[0]].push_back(e[1]);
        }

        for (int i = 0; i < n; i++) {
            if (visited[i] == 0 && !dfs(colors, i)) {
                return -1;
            }
        }

        return maxVal;
    }
};
// @lc code=end

