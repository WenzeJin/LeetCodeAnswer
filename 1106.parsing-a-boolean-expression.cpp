/*
 * @lc app=leetcode.cn id=1106 lang=cpp
 *
 * [1106] Parsing A Boolean Expression
 */

#include <stack>

using namespace std;



// @lc code=start
class Solution {
    stack<char> opt;
    stack<int> ops;

    void popOp() {
        char op = opt.top();
        opt.pop();
        if (op == '!') {
            bool op1 = ops.top();
            ops.pop();
            ops.push(!op1);
            return;
        } else if (op == '&') {
            bool res = true;
            while (ops.top() != 2) {
                res = res && ops.top();
                ops.pop();
            }
            ops.pop(); // pop bound 2
            ops.push(res);
        } else if (op == '|') {
            bool res = false;
            while (ops.top() != 2) {
                res = res || ops.top();
                ops.pop();
            }
            ops.pop(); // pop bound 2
            ops.push(res);
        }
    }

public:
    bool parseBoolExpr(string expression) {
        
        size_t pt = 0;
        int n = expression.length();
        while (pt < n) {
            switch (expression[pt]) {
                case ',': {
                    break;
                }
                case 't': {
                    ops.push(true);
                    break;
                }
                case 'f': {
                    ops.push(false);
                    break;
                }
                case '!': case '&': case '|': {
                    char op = expression[pt];
                    pt++; // skip '('
                    opt.push(op);
                    if (op == '&' || op == '|') {
                        ops.push(2); //push bound 2
                    }
                }
                case ')': {
                    popOp();
                }
            }
            pt++;
        }

        return ops.top();
    }
};
// @lc code=end

