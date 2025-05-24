/*
 * @lc app=leetcode.cn id=2685 lang=cpp
 *
 * [2685] Count the Number of Complete Components
 */


#include <vector>
#include <unordered_set>

using namespace std;

// @lc code=start
class Solution {
    vector<unordered_set<int>> g; // 用集合，一会儿可以快速判断某条边存不存在
    vector<int> group;

public:
    void dfs(int curr, int g_no) {
        group[curr] = g_no;
        for (int out: g[curr]) {
            if (group[out] == -1) {
                dfs(out, g_no);
            }
        }
    }


    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        g = vector<unordered_set<int>>(n);
        group = vector<int>(n, -1);
        
        for (auto& e: edges) {
            g[e[0]].insert(e[1]);
            g[e[1]].insert(e[0]);
        }
        
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (group[i] == -1) {
                dfs(i, cnt);
                cnt++;
            }
        }

        vector<bool> comp(cnt, true);

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (group[i] == group[j] && g[i].find(j) == g[i].end()) {
                    comp[group[i]] = false;
                }
            }
        }

        int res = 0;
        for (int i = 0; i < cnt; i++) {
            if (comp[i]) res++;
        }
        return res;
    }
};
// @lc code=end

