/*
 * @lc app=leetcode.cn id=650 lang=cpp
 *
 * [650] 两个键的键盘
 */

// @lc code=start
#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
    int minSteps(int n) {
        // 已经知道 1 .. n - 1 的最少次数
        // 如果当前剪贴板里有 k 个，那么最少次数是 n - k 的最少次数 + 1 剪贴版里仍然是 k 个
        // 此时再做一个 Copy All 剪贴版里就变成 n 个
        // vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MAX));
        // dp[1][0] = 0;
        // dp[1][1] = 1;
        // for (int i = 2; i <= n; i++) {

        //     for (int j = 1; j < i; j++) {
        //         for (int k = 1; k <= j; k++) {
        //             // k 代表剪贴板里有的数量，j 代表当前已经在记事本中的数量
        //             if (j + k == i && dp[j][k] != INT_MAX) {
        //                 dp[i][k] = min(dp[i][k], dp[j][k] + 1);
        //             } else if (j + k > i) {
        //                 break;
        //             }
        //         }
        //     }

        //     int min_i = *min_element(dp[i].begin(), dp[i].end());

        //     dp[i][i] = min_i + 1;
        // }

        // return dp[n][n] - 1;

        // 继续优化上面的 DP，我们可以发现，如果需要得到 i 个A，肯定是在刚刚得到 j 个 A 的基础上，进行一次复制全部操作，然后再 粘贴 i/j - 1 次，这里要求 j 一定是 i 的因数。优化成 1维 DP dp[i] = dp[j] * i/j
        // 这里我们做的优化实际上就是去掉了大部分都无意义的第二维，也就是剪贴板里的保存。
        vector<int> dp(n + 1, INT_MAX);

        dp[1] = 0;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i / 2; j++) {
                if (i % j == 0) {
                    dp[i] = min(dp[i], dp[j] + (i / j));
                }
            }
        }
        return dp[n];

        // 继续优化，我们会发现上面的方法实际上就可以看作一种分解质因数的操作，我们直接对 n 分解质因数就可以了，这里就不继续优化了

    }
};
// @lc code=end

