/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
#include <string>

using namespace std;

class Solution {

    int getLayer(char c) {
        switch (c) {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        }
        return 0;
    }

public:
    int romanToInt(string s) {
        int curr_lay = -1;
        int curr_cnt = 0;
        int curr_num = 0;
        for (char c: s) {
            int layer = getLayer(c);
            if (curr_lay == -1) {
                curr_lay = layer;
                curr_cnt = 1;
            } else if (curr_lay < layer) {
                curr_num -= curr_lay * curr_cnt;
                curr_lay = layer;
                curr_cnt = 1;
            } else if (curr_lay == layer) {
                curr_cnt++;
            } else if (curr_lay > layer) {
                curr_num += curr_lay * curr_cnt;
                curr_lay = layer;
                curr_cnt = 1;
            }
        }
        if (curr_cnt != 0) {
            curr_num += curr_lay * curr_cnt;
        }
        return curr_num;
    }
};
// @lc code=end

