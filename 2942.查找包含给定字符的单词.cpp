/*
 * @lc app=leetcode.cn id=2942 lang=cpp
 *
 * [2942] 查找包含给定字符的单词
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> res;
        for (int i = 0; i < words.size(); i++) {
            if (words[i].find(x) != words[i].npos) {
                res.push_back(i);
            }
        }
        return std::move(res);
    }
};
// @lc code=end

