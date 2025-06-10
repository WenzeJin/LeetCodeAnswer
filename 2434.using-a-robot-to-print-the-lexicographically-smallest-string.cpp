/*
 * @lc app=leetcode.cn id=2434 lang=cpp
 *
 * [2434] Using a Robot to Print the Lexicographically Smallest String
 */

#include <string>
#include <stack>
#include <sstream>

using namespace std;

// @lc code=start
class Solution {
public:
    string robotWithString(string s) {
        // 所谓的 t 字符串，实际上就是一个栈，我们贪心地构建字符串：
        // 1. 如果后面还可能遇到更小的字符，我们要不断压栈，直到把这个字符压栈
        // 2. 如果后面不可能遇到比栈顶更小的字符，就不断弹栈，直到栈空
        // 可以用反证法说明上述方法是正确的。
        // 所以需要预先处理从此处之后可能遇到的最大字符
        vector<char> min_char(s.length());

        char mc = s.back();
        for (int i = s.length() - 1; i >= 0; i--)  {
            mc = min(mc, s[i]);
            min_char[i] = mc;
        }

        stack<char> t;
        int pt = 0;
        stringstream ans;

        while(!t.empty() || pt < s.length()) {
            if (t.empty()) {
                t.push(s[pt]);
                pt++;
            } else if (pt == s.length()) {
                ans << t.top();
                t.pop();
            } else {
                if (t.top() > min_char[pt]) {
                    // 这里要注意优先弹出：如果栈顶等于 min_char，优先弹出，否则可能压入阻碍我们的字符
                    t.push(s[pt]);
                    pt++;
                } else {
                    ans << t.top();
                    t.pop();
                }
            }
        }

        return ans.str();

    }
};
// @lc code=end

