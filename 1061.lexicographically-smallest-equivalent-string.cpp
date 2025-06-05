/*
 * @lc app=leetcode.cn id=1061 lang=cpp
 *
 * [1061] Lexicographically Smallest Equivalent String
 */

#include <vector>
#include <string>
#include <sstream>

using namespace std;

// @lc code=start
class UFSet {
    vector<int> table;

    int getPos(char c) {
        return c - 'a';
    }

public:

    UFSet() : table(26, -1) {}

    int find(char c) {
        int i = getPos(c);
        while (table[i] >= 0) {
            i = table[i];
        }
        int res = i;
        // 路径压缩
        i = getPos(c);
        while (table[i] >= 0) {
            int p = table[i];
            table[i] = res;
            i = p;
        }
        return res;
    }

    void uunion(char a, char b) {
        int ag = find(a);
        int bg = find(b);
        if (ag == bg) {
            return;
        }
        if (ag < bg) {
            table[ag] = table[ag] + table[bg];
            table[bg] = ag;
        } else {
            table[bg] = table[ag] + table[bg];
            table[ag] = bg;
        }
    }
};

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        // 用 UFSet 加速获取最小等价字符串，这里对 UFSet 进行特殊设计，使得每个等价类的代表元就是最小的那个，所以我们只要用代表元代替某个位置的字符，自然就能贪心地构造出最小字符串。
        int n = s1.length();
        UFSet ufset;
        for (int i = 0; i < n; i++) {
            ufset.uunion(s1[i], s2[i]);
        }
        stringstream ss;
        for (char c: baseStr) {
            ss << (char)(ufset.find(c) + 'a');
        }
        return ss.str();
    }
};
// @lc code=end

