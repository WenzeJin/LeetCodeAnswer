/*
 * @lc app=leetcode.cn id=2086 lang=cpp
 *
 * [2086] Minimum Number of Food Buckets to Feed the Hamsters
 */

#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    int minimumBuckets(string hamsters) {
        // 先检查是否可满足，不可满足当且仅当有一只仓鼠前后都是仓鼠，顺便统计仓鼠数量
        int cnt = 0;
        for (int i = 1; i < hamsters.length() - 1; i++) {
            if (hamsters[i] == 'H') {
                cnt++;
                if (hamsters[i - 1] == 'H' && hamsters[i + 1] == 'H') {
                    return - 1;
                }
            }
        }
        if (hamsters[0] == 'H') {
            if (hamsters.length() == 1 || hamsters[1] == 'H') {
                return -1;
            }
            cnt++;
        }
        if (hamsters.length() > 1) {
            if (hamsters[hamsters.length() - 1] == 'H') {
                if (hamsters[hamsters.length() - 2] == 'H') {
                    return -1;
                }
                cnt++;
            }
        }
        // 现在一个坑可以满足0、1、2只仓鼠所需，先使用所有可以满足 2 只仓鼠的坑
        int res = 0;
        for (int i = 1; i < hamsters.length() - 1; i++) {
            if (hamsters[i] == '.' && hamsters[i - 1] == 'H' && hamsters[i + 1] == 'H') {
                cnt -= 2;
                res++;
                hamsters[i - 1] = hamsters[i] = hamsters[i + 1] = 'x';
            }
        }
        // 剩下每一只仓鼠都需要一个桶
        return res + cnt;
    }
};
// @lc code=end

