/*
 * @lc app=leetcode.cn id=3021 lang=cpp
 *
 * [3021] Alice and Bob Playing Flower Game
 */

// @lc code=start
class Solution {
public:
    long long flowerGame(int n, int m) {
        // 实际上就是问 x + y 为奇数的组合个数
        long long n_e = n / 2;
        long long n_o = n / 2 + (n % 2 == 1);

        long long m_e = m / 2;
        long long m_o = m / 2 + (m % 2 == 1);

        return n_e * m_o + n_o * m_e;

    }
};
// @lc code=end

