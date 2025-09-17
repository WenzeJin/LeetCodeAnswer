/*
 * @lc app=leetcode.cn id=1449 lang=cpp
 *
 * [1449] Form Largest Integer With Digits That Add up to Target
 */

#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    string largestNumber(vector<int>& cost, int target) {
        // 完全背包问题，一个数位可以多次添加。
        // 如何做到数字尽可能大？首先，应该选取更多的数字位数，所以 dp[i][j] 表示我们能够选取的最多数字位数，如果不能够选择达到target，则为 -1。同时用 from 数组记录转移来源。
        // 最终从 dp[9][target] 回溯，由于我们在同样的数量下，要尽可能添加大的数字，所以优先使用该数位进行转移，因此这对 from 数组的记录有要求。(from[i][j] == j, 说明从 [i - 1][j] 转移，否则从[i][j - cost[i - 1]] 转移)

        int n = 9;
        int m = target + 1;
        vector<vector<int>> dp(n + 1, vector<int>(m, -1));
        vector<vector<int>> from(n + 1, vector<int>(m));
        dp[0][0] = 0;
        from[0][0] = -1;

        for (int i = 1; i <= n; i++) {
            dp[i][0] = 0;
            from[i][0] = -1;
            for (int j = 1; j <= target; j++) {
                if (dp[i - 1][j] >= 0) {
                    dp[i][j] = dp[i - 1][j];
                    from[i][j] = j;
                }
                if (j >= cost[i - 1] && dp[i][j - cost[i - 1]] >= 0) {
                    if (dp[i][j - cost[i - 1]] + 1 >= dp[i][j]) {
                        // 优先使用
                        dp[i][j] = dp[i][j - cost[i - 1]] + 1;
                        from[i][j] = j - cost[i - 1];
                    }
                }
            }
        }

        if (dp[9][target] <= 0) {
            return "0";
        }

        vector<char> buffer;

        int i = 9, j = target;

        while(from[i][j] >= 0) {
            if (from[i][j] == j) {
                i--;
            } else {
                j = from[i][j];
                buffer.push_back('0' + i);
            }
        }

        return string(buffer.begin(), buffer.end());
    }
};
// @lc code=end

