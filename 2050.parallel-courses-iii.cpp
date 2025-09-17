/*
 * @lc app=leetcode.cn id=2050 lang=cpp
 *
 * [2050] Parallel Courses III
 */

#include <vector>
#include <queue>

using namespace std;

// @lc code=start
class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> gin(n + 1);
        vector<vector<int>> gout(n + 1);
        for (auto& r: relations) {
            gin[r[1]].push_back(r[0]);
            gout[r[0]].push_back(r[1]);
        }

        queue<int> zero;
        vector<int> deg(n + 1);
        for (int i = 1; i <= n; i++) {
            deg[i] = gin[i].size();
            if (deg[i] == 0) {
                zero.push(i);
            }
        }

        int max_t = 0;

        while (!zero.empty()) {
            int i = zero.front();
            zero.pop();
            // dp 重复利用 deg
            deg[i] = time[i - 1];
            for (int in: gin[i]) {
                deg[i] = max(deg[i], deg[in] + time[i - 1]);
            }
            max_t = max(max_t, deg[i]);
            for (int o: gout[i]) {
                deg[o]--;
                if (deg[o] == 0) {
                    zero.push(o);
                }
            }
        }

        return max_t;

    }
};
// @lc code=end

