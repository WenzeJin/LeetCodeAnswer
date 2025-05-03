/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
#include <string>
#include <iostream>
#define INTMAX 2147483647
#define INTMIN -2147483648

using namespace std;

inline int safeAdd(int a, int b) {
    // assert sign of a is same as b
    long long res = (long long)a +(long long) b;
    if (res > INTMAX) {
        res = INTMAX;
    } else if (res < INTMIN) {
        res = INTMIN;
    }
    return (int)res;
}

inline int safeMut(int a) {
    long long res = (long long)a * 10;
    if (res > INTMAX) {
        res = INTMAX;
    } else if (res < INTMIN) {
        res = INTMIN;
    }
    return (int)res;
}

inline bool isDigit(char c) {
    return c >= '0' && c <= '9';
}

class Solution {
public:
    int myAtoi(string s) {
        int sign = 1;
        bool sFlag = false;
        int res = 0;
        for (char c : s) {
            if (!sFlag && c == ' ') {
                continue;
            }

            if (!sFlag && c == '-') {
                sign = -1;
                sFlag = true;
                continue;
            } else if (!sFlag && c == '+') {
                sign = 1;
                sFlag = true;
                continue;
            }

            if (isDigit(c)) {
                sFlag = true;
                res = safeMut(res);
                res = safeAdd(res, (c - '0') * sign);
                if (res >= INTMAX || res <= INTMIN) {
                    break;
                }
            } else {
                break;
            }
        }
        return res;
    }
};
// @lc code=end

