/*
 * @lc app=leetcode.cn id=2742 lang=cpp
 *
 * [2742] Painting the Walls
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int paintWalls(vector<int> &cost, vector<int> &time) {
        // 付费时长 >= 免费时长 = 免费个数
        // 付费时长 >= n - 付费个数
        // sum(付费时长 + 1) >= n
        int n = cost.size();
        vector<int> f(n + 1, INT_MAX / 2); // 防止加法溢出
        f[0] = 0;
        for (int i = 0; i < n; i++) {
            int c = cost[i], t = time[i] + 1; // 注意这里加一了
            for (int j = n; j; j--) {
                f[j] = min(f[j], f[max(j - t, 0)] + c);
            }
        }
        return f[n];
    }
};

// @lc code=end

