/*
 * @lc app=leetcode.cn id=960 lang=cpp
 *
 * [960] Delete Columns to Make Sorted III
 */

#include <vector>
#include <string>
#include <cassert>
#include <sstream>

using namespace std;

// @lc code=start
class Solution {
    int lessThan(string& a, string& b) {
        assert(a.length() == b.length());
        for (int i = 0; i < a.length(); i++) {
            if (a[i] > b[i]) {
                return false;
            }
        }
        return true;
    }

public:
    int minDeletionSize(vector<string>& strs) {
        vector<string> temp;
        int l = strs[0].length();
        for (int i = 0; i < l; i++) {
            stringstream ss;
            for (auto& s: strs) {
                ss << s[i];
            }
            temp.push_back(ss.str());
        }

        vector<int> dp(l); // 转化为 LIS 问题
        dp[0] = 1;
        for (int i = 1; i < l; i++) {
            dp[i] = 1;
            for (int j = 0; j < i; j++) {
                if (lessThan(temp[j], temp[i])) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        
        return dp[l - 1];
    }
};
// @lc code=end

