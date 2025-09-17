/*
 * @lc app=leetcode.cn id=2896 lang=cpp
 *
 * [2896] Apply Operations to Make Two Strings Equal
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int minOperations(string s1, string s2, int x) {
        // 首先统计需要修改的位置 p[i]
        // p[i] 一定是偶数，否则无法修改。
        // 接着，用 dp[i] 表示完成 前 i 个修改需要的代价
        // dp[i] 从两个方式得到
        // 通过连续的 i ～ i + 1 变换，同时反转 p[i - 2] 和 p[i - 1]，此时，需要 p[i - 1] - p[i - 2] 次操作
        // 通过任意的两个位置交换，平摊费用为 x / 2，要求一共进行偶数次这种变换，通过上面的分析可以保证这样的变换是偶数次。

        vector<int> p;
        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] != s2[i]) {
                p.push_back(i);
            }
        }

        int n = p.size();
        if (n % 2 == 1) {
            return -1;
        }
        if (n == 0) {
            return 0;
        }

        vector<int> dp(n + 1);
        dp[1] = x; // 翻倍方便统计
        for (int i = 2; i <= n; i++) {
            dp[i] = min(dp[i - 1] + x, 2 * (p[i - 1] - p[i - 2]) + dp[i - 2]);
        }
        return dp[n] / 2;
    }
};
// @lc code=end

