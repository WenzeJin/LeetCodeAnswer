/*
 * @lc app=leetcode.cn id=537 lang=cpp
 *
 * [537] Complex Number Multiplication
 */

#include <string>
#include <vector>
#include <sstream>

using namespace std;

// @lc code=start
class Solution {

    vector<int> parse(string num) {
        vector<int> res(2);
        int p = 0;
        while (num[p] != '+') {
            p++;
        }
        res[0] = stoi(num.substr(0, p));
        int s = ++p;
        while (num[p] != 'i') {
            p++;
        }
        res[1] = stoi(num.substr(s, p - s));
        return res;
    }

public:
    string complexNumberMultiply(string num1, string num2) {
        auto v1 = parse(num1);
        auto v2 = parse(num2);

        vector<int> r(2);
        r[0] = v1[0] * v2[0] - v1[1] * v2[1];
        r[1] = v1[0] * v2[1] + v1[1] * v2[0];

        stringstream ss;
        ss << r[0] << '+' << r[1] << 'i';
        return ss.str();
    }
};



// @lc code=end

