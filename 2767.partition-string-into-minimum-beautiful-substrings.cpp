/*
 * @lc app=leetcode.cn id=2767 lang=cpp
 *
 * [2767] Partition String Into Minimum Beautiful Substrings
 */

#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int minimumBeautifulSubstrings(string s) {
        // dp[i] 表示前 i 个字符的最少分割数，如果不可分割为 -1
        // 一个数，如果结尾是 0，则一定不可能，因为是偶数。

        int n = s.length();
        vector<int> dp(n + 1, -1);
        dp[0] = 0;

        for (int i = 1; i <= n; i++) {
            if (s[i - 1] == '1') {
                int sum = 1;
                if (dp[i - 1] >= 0) {
                    dp[i] = dp[i - 1] + 1;
                }
                int cnt = 0;
                for (int j = i - 2; j >= 0; j++) {
                    cnt++;
                    if (s[j] == '1') {
                        sum += (1 << cnt);
                        int x = sum;
                        while (x > 1) {
                            x /= 5;
                        }
                        if (x == 1) {
                            dp[i] = min(dp[i], dp[j] + 1);
                        }
                    }
                }
            }
        }

        return dp[n];
    }
};
// @lc code=end

