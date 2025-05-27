/*
 * @lc app=leetcode.cn id=3561 lang=cpp
 *
 * [3561] Resulting String After Adjacent Removals
 */

#include <cstdlib>
#include <string>
#include <deque>

using namespace std;

// @lc code=start
class Solution {
public:
    string resultingString(string s) {
        deque<char> buffer;
        for (char c: s) {
            if (!buffer.empty() && (abs(buffer.back() - c) == 1 || abs(buffer.back() - c) == 25)) {
                buffer.pop_back();
            } else {
                buffer.push_back(c);
            }
        }
        return string(buffer.begin(), buffer.end());
    }
};
// @lc code=end

