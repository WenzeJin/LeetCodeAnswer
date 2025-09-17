/*
 * @lc app=leetcode.cn id=2904 lang=cpp
 *
 * [2904] Shortest and Lexicographically Smallest Beautiful String
 */

#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        vector<int> cnt = {0, 0};
        // 找满足条件的最小长度

        int left = 0, right = 0; 
        string res = "";

        for (right = 0; right < s.length(); right++) {
            // move in
            int x = s[right] - '0';
            cnt[x]++;

            if (cnt[1] == k) {
                while (cnt[1] == k) {
                    int x = s[left] - '0';
                    cnt[x]--;
                    left++;
                }

                int l = right - left + 2;
                if (l <= res.length() || res == "") {
                    string ns = s.substr(left - 1, l);
                    if (l < res.length() || res == "") {
                        res = move(ns);
                    } else if(ns < res) {
                        res = move(ns);
                    }
                }
            }
        }

        return res;
    }
};
// @lc code=end

