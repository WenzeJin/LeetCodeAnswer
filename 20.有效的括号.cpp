/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start

#include <string>
#include <stack>

using namespace std;

class Solution {
    stack<char> stack;

  public:
    bool isValid(string s) {
        stack.push('Z');

        for (char c: s) {
            switch(c) {
            case '(': case '{': case '[':
                stack.push(c);
                break;
            case ')':
                if (stack.top() != '(') {
                    return false;
                }
                stack.pop();
                break;
            case ']':
                if (stack.top() != '[') {
                    return false;
                }
                stack.pop();
                break;
            case '}':
                if (stack.top() != '{') {
                    return false;
                }
                stack.pop();
                break;
            }
        }

        return stack.top() == 'Z';
    }
};
// @lc code=end

