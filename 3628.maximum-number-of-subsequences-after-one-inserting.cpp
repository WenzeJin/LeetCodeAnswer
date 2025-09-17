/*
 * @lc app=leetcode.cn id=3628 lang=cpp
 *
 * [3628] Maximum Number of Subsequences After One Inserting
 */

#include <vector>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    long long numOfSubsequences(string s) {
        // 在一个位置插入字母，新增的 LCT 数量为：
        // 如果插入 L：右侧 CT 数量
        // 如果插入 C：左侧 L * 右侧 T 数量
        // 如果插入 T：左侧 LC 数量
        int n = s.length();
        vector<vector<long long>> dp(n + 1, vector<long long>(4));
        // 分别为 L LC CT T
        // 先统计 L 和 LC
        for (int i = 1; i <= n; i++) {
            if (s[i - 1] == 'L') {
                dp[i][0] = dp[i - 1][0] + 1;
                dp[i][1] = dp[i - 1][1];
            } else if (s[i - 1] == 'C') {
                dp[i][1] = dp[i - 1][1] + dp[i - 1][0];
                dp[i][0] = dp[i - 1][0];
            } else {
                dp[i][0] = dp[i - 1][0];
                dp[i][1] = dp[i - 1][1];
            }
        }
        long long tot = 0;
        // 再统计 T 和 CT，顺便统计目前的 LCT 数量
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == 'T') {
                dp[i][3] = dp[i + 1][3] + 1;
                dp[i][2] = dp[i + 1][2];
                tot += dp[i][1]; // 统计数量
            } else if (s[i] == 'C') {
                dp[i][2] = dp[i + 1][2] + dp[i + 1][3];
                dp[i][3] = dp[i + 1][3];
            } else {
                dp[i][2] = dp[i + 1][2];
                dp[i][3] = dp[i + 1][3];
            }
        }
        // for (auto& v: dp) {
        //     cout << v[0] << " " << v[1] << " " << v[2] << " " << v[3] << endl;
        // }
        // cout << tot << endl;

        long long max_d = 0;
        for (auto& v: dp) {
            max_d = max(max_d, v[1]);
            max_d = max(max_d, v[2]);
            max_d = max(max_d, v[0] * v[3]);
        }

        return tot + max_d;
    }
};
// @lc code=end

