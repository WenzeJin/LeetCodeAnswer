/*
 * @lc app=leetcode.cn id=2516 lang=cpp
 *
 * [2516] Take K of Each Character From Left and Right
 */

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
public:
    int takeCharacters(string s, int k) {
        // 即求最大滑动窗口，使得窗口内元素去掉后剩余元素大于 K
        unordered_map<char, int> cnt;
        cnt['a'] = 0;
        cnt['b'] = 0;
        cnt['c'] = 0;
        for (char x: s) {
            cnt[x]++;
        }

        // 预处理能保留的最大数量
        for (auto& kv: cnt) {
            if (kv.second < k) {
                return -1; // 本身数量就不够
            }
            kv.second -= k;
        }

        int left = 0, right = 0, res = 0;
        for (right = 0; right < s.length(); right++) {
            // move in
            char c = s[right];
            cnt[c]--;

            while (cnt[c] < 0) {
                char c = s[left];
                cnt[c]++;
                left++;
            }

            res = max(res, right - left + 1);
        }

        return s.length() - res;
    }
};
// @lc code=end

