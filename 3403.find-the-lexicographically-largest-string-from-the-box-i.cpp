/*
 * @lc app=leetcode.cn id=3403 lang=cpp
 *
 * [3403] Find the Lexicographically Largest String From the Box I
 */

#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    string answerString(string word, int numFriends) {
        // 首先，明确一点：长度越长的字典序越大，所以最大的串长度肯定是 word.length() - numFirends + 1
        // 其次，说是分很多次，其实毫无意义，切分只是限制了单个串的最大长度，只需要关注所有长度为上述长度的字串就可以了，但是靠近末尾时要注意，可能剩下的串长度不能满足上述长度，也要考虑。
        // 因此，贪心地找所有尽可能长的子串。
        if (numFriends == 1) {
            return word;
        }

        int maxLen = word.length() - numFriends + 1;
        string maxstr = "";

        for (int i = 0; i < word.length(); i++) {
            int len = min(maxLen, (int)word.length() - i);
            string substr = word.substr(i, len);
            maxstr = max(maxstr, substr);
        }

        return maxstr;

    }
};
// @lc code=end

