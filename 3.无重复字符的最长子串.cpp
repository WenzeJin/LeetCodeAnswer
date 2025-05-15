/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start

#include <unordered_map>
#include <string>
#include <cmath>
#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> window;

        int left = 0, right = 0;
        int unique = 0; // 其实不用记录 unique，我们始终想让窗口内无重复，所以一旦某个字符出现重复，就缩小直到这个重复被消解就可以了，此时自然别的字符也不会重复
        int len = 0;
        // window is [left, right)
        while (right < s.size()) {
            // move in
            char c = s[right];
            right++;

            if (window[c] == 1) {
                unique--;
            }
            window[c]++;
            if (window[c] == 1) {
                unique++;
            }

            // 我们要找到最长的无重复字串，所以一旦出现重复再缩小
            while (right - left > unique) {
                char c = s[left];
                left++;
                if (window[c] == 1) {
                    unique--;
                }
                window[c]--;
                if (window[c] == 1) {
                    unique++;
                }
            }

            // 重复被消解了，现在检查是否满足条件和更新
            if (right - left == unique) {
                len = max(right - left, len);
            }
        }
        return len;
    }
};
// @lc code=end

