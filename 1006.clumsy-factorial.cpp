/*
 * @lc app=leetcode.cn id=1006 lang=cpp
 *
 * [1006] Clumsy Factorial
 */

#include <stack>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
    stack<int> val;
    stack<char> op;

    void calc() {
        int op2 = val.top();
        val.pop();
        int op1 = val.top();
        val.pop();
        switch(op.top()) {
            case '+':
            val.push(op1 + op2);
            break;
            case '-':
            val.push(op1 - op2);
            break;
            case '*':
            val.push(op1 * op2);
            break;
            case '/':
            val.push(op1 / op2);
            break;
        }
        op.pop();
    }

    void pushOp(char x) {
        if (op.empty()) {
            op.push(x);
            return;
        }
        if (op.top() == '*' || op.top() == '/') {
            calc();
            pushOp(x);
        } else {
            if (x == '+' || x == '-') {
                calc();
                pushOp(x);
            } else {
                pushOp(x);
            }
        }
    }

public:
    int clumsy(int n) {
        vector<char> ops = {'*', '/', '+', '-'};

        val.push(n);
        n--;
        int pt = 0;
        while(n > 0) {
            char next = ops[pt % 4];
            val.push(n);
            pushOp(next);
        }
        while (!op.empty()) {
            calc();
        }
        return val.top();
    }
};
// @lc code=end

