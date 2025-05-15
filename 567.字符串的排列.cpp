/*
 * @lc app=leetcode.cn id=567 lang=cpp
 *
 * [567] 字符串的排列
 */

// @lc code=start
#include <unordered_set>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> need, window;

        // init need
        for(char c: s1) { 
            need[c]++;
        }

        int left = 0, right = 0;
        int valid = 0;

        // window is [left, right)
        while(right < s2.size()) {
            // move in
            char c = s2[right];
            right++;

            // count
            if (need.contains(c)) {
                window[c]++;
                if (window[c] == need[c]) {
                    valid++;
                }
            }

            // while window's length >= s2.size() we can move out
            while(right - left >= s1.size()) {
                // check valid
                if (right - left  == s1.size()) {
                    if (valid == need.size()) {
                        return true;
                    }
                }

                // move out
                char c = s2[left];
                left++;
                if (need.contains(c)) {
                    if (window[c] == need[c]) {
                        valid--;
                    }
                    window[c]--;
                }
            }
        }

        // find nothing
        return false;
    }
};
// @lc code=end

