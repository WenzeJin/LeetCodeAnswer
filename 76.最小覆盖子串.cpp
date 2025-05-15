/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need, window;
        int valid = 0;

        int left = 0, right = 0;
        int start = 0, len = INT_MAX;

        // init need;
        for (char c: t) {
            need[c]++;
        }

        // window is [left, right)
        while(right < s.size()) {
            // move in
            char c = s[right];
            right++;
            

            // if window[c] met need[c], this character now has a valid number
            if (need.contains(c)) {
                window[c]++;
                if (window[c] == need[c]) {
                    valid++;
                }
            }
            

            while(valid == need.size()) {
                // now is valid, update answer
                if (right - left < len) {
                    len = right - left;
                    start = left;
                }

                // move out
                char c = s[left];
                if (need.contains(c)) {
                    if (window[c] == need[c]) {
                        valid--;    // not valid after moving out
                    }
                    window[c]--;
                }
                
                
                left++;
            }
        }

        return len == INT_MAX ? "" : s.substr(start, len);
    }
};
// @lc code=end

