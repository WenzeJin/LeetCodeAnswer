/*
 * @lc app=leetcode.cn id=1591 lang=cpp
 *
 * [1591] Strange Printer II
 */

#include <queue>
#include <vector>
#include <unordered_set>

using namespace std;

// @lc code=start
class Solution {
public:
  bool isPrintable(vector<vector<int>> &targetGrid) {
    int g[61][61] = {0};
    vector<vector<int>> area(61, vector<int>(4, -1));
    unordered_set<int> colors;

    // 找每种颜色的矩形边界
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        int x = targetGrid[i][j];
        colors.insert(x);
        if (area[x][0] == -1) {
          area[x] = {i, j, i, j};
        } else {
          area[x][0] = min(area[x][0], i);
          area[x][1] = min(area[x][1], j);
          area[x][2] = max(area[x][2], i);
          area[x][3] = max(area[x][3], j);
        }
      }
    }

    // 建依赖图
    for (int k : colors) {
      for (int i = area[k][0]; i <= area[k][2]; i++) {
        for (int j = area[k][1]; j <= area[k][3]; j++) {
          if (targetGrid[i][j] != k) {
            g[k][targetGrid[i][j]] = 1;
          }
        }
      }
    }

    // 拓扑排序
    int deg[61] = {0};
    for (int i = 0; i < 61; i++) {
      for (int j = 0; j < 61; j++) {
        if (g[i][j])
          deg[j]++;
      }
    }
    queue<int> q;
    for (int c : colors) {
      if (deg[c] == 0)
        q.push(c);
    }

    int visited = 0;
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      visited++;
      for (int v = 0; v < 61; v++) {
        if (g[u][v]) {
          if (--deg[v] == 0)
            q.push(v);
        }
      }
    }

    return visited == (int)colors.size();
  }
};
// @lc code=end
