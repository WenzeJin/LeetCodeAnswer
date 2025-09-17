/*
 * @lc app=leetcode.cn id=2606 lang=cpp
 *
 * [2606] Find the Substring With Maximum Cost
 */

#include <climits>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        unordered_map<char, int> value;
        for (char c = 'a'; c <= 'z'; c++) {
            value[c] = c - 'a' + 1;
        }
        for (int i = 0; i < chars.length(); i++) {
            value[chars[i]] = vals[i];
        }
        int maxVal = 0;
        // dp[i] 是以 s[i] 结尾的最大值
        int prev = value[s[0]];
        int curr;
        maxVal = max(prev, maxVal);
        for (int i = 1; i < s.length(); i++) {
            curr = max(prev, 0) + value[s[i]];
            maxVal = max(maxVal, curr);
            prev = curr;
        }
        return maxVal;
    }
};
// @lc code=end

