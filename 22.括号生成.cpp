/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
    vector<char> buffer;
    vector<string> res;

public:
    // left 就是我们欠下的 ( 的债, remaining 是我们最多还能还多少债
    void dfs(int remaining, int left) {
        if (remaining == left) {
            for (int i = 0; i < remaining; i++) {
                buffer.push_back(')');
            }
            res.push_back(string(buffer.begin(), buffer.end()));
            for (int i = 0; i < remaining; i++) {
                buffer.pop_back();
            }
            return;
        } else if (remaining < left) {
            return;
        } else if (remaining == 0) {
            return;
        }

        // fill in ( or )
        buffer.push_back('(');
        dfs(remaining - 1, left + 1);
        buffer.pop_back();
        if (left > 0) {
            buffer.push_back(')');
            dfs(remaining - 1, left - 1);
            buffer.pop_back();
        }
    } 


    vector<string> generateParenthesis(int n) {
        dfs(n * 2, 0);

        return std::move(res);
    }
};
// @lc code=end

