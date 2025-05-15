/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start

#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        unordered_map<char, int> need, window;

        // init need;
        for(char c: p) {
            need[c]++;
        }

        int left = 0, right = 0;
        int valid = 0;

        while (right < s.size()) {
            // move in
            char c = s[right];
            right++;

            if (need.contains(c)) {
                window[c]++;
                if (window[c] == need[c]) {
                    valid++;
                }
            }

            while (right - left >= p.size()) {
                // check answer
                if (right - left == p.size()) {
                    if (valid == need.size()) {
                        res.push_back(left);
                    }
                }

                // move out
                char c = s[left];
                left++;

                if (need.contains(c)) {
                    if (window[c] == need[c]) {
                        valid--;
                    }
                    window[c]--;
                }
            }
        }
        return res;
    }
};
// @lc code=end

