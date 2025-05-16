/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */

// @lc code=start

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {

        if (word1.size() < word2.size()) {
            swap(word1, word2);
        }

        vector<int> i1(word2.size() + 1);
        vector<int> i2(word2.size() + 1);

        // dp[i][j] 表示将 word1[1..=i] 转换为 word2[1..=j] 的最小编辑距离
        // 这里进一步优化，仅保留上一行 dp，为 i1，这一行的dp为 i2


        for (int j = 0; j <= word2.size(); j++) {
            i1[j] = j;  // 全部增加
        }

        for (int i = 1; i <= word1.size(); i++) {

            i2[0] = i;
            for (int j = 1; j <= word2.size(); j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    i2[j] = i1[j - 1];
                } else {
                    i2[j] = min({i2[j - 1], i1[j - 1], i1[j]}) + 1;
                }

                // 将 word1[1..=i] 转换为 word2[1..=j]
                // 可以选择删掉一个字母，再将 word1[1..=i-1] 转换为 word2[1..=j]
                // 也可以选择增加一个字母，相当于最后一个字母已经转换好，要将 word1[1..=i] 转换为 word2[1..=j-1]
                // 也可以修改一个字母，即将 word1[1..=i-1] 转换为 word2[1..=j-1]，如果这两个字母相同，可以不转换

            }
            swap(i1, i2);
        }

        return i1[word2.size()];
    }
};
// @lc code=end

