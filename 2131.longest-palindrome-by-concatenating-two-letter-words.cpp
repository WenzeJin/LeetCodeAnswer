/*
 * @lc app=leetcode.cn id=2131 lang=cpp
 *
 * [2131] Longest Palindrome by Concatenating Two Letter Words
 */

#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        // 用哈希表记录出现次数，贪心的选择某一个和它的镜像就可以了，之道不能选择为止。出现在最中间的可以是单个，但其必须本身对称

        // 统计
        unordered_map<string, int> occur;
        for (string& w: words) {
            ++occur[w];
        }

        bool center = true; // 中心仍未确定
        int len = 0;
        for (auto& kv: occur) {
            if (kv.second == 0) {
                continue;
            }
            const string& key = kv.first;
            string rev(key.rbegin(), key.rend());
            if (key == rev) {
                // 本身是两个相同的字符
                if (center && kv.second % 2 == 1) {
                    center = false;
                    len += kv.second * 2; // 此时可以使用 1 次（在中心）+ 偶数次
                } else {
                    len += (kv.second / 2) * 2 * 2; // 只能使用偶数次
                }
            } else {
                if (occur.find(rev) == occur.end()) {
                    continue;
                }
                int t = min(kv.second, occur[rev]);
                kv.second -= t;
                occur[rev] -= t;
                len += t * 2 * 2;
            }
        }

        return len;
    }
};
// @lc code=end

