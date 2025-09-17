/*
 * @lc app=leetcode.cn id=3622 lang=cpp
 *
 * [3622] Check Divisibility by Digit Sum and Product
 */

// @lc code=start
class Solution {
public:
    bool checkDivisibility(int n) {
        int nn = n;
        int pro = 1, sum = 0;
        while (nn > 0) {
            int digit = nn % 10;
            pro *= digit;
            sum += digit;
            nn /= 10;
        }
        return n % (pro + sum) == 0;
    }
};
// @lc code=end

