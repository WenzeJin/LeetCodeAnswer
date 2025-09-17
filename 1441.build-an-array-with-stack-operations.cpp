/*
 * @lc app=leetcode.cn id=1441 lang=cpp
 *
 * [1441] Build an Array With Stack Operations
 */

#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int i = 1;
        int p = 0;
        vector<string> res;
        while (p != target.size()) {
            while (i < target[p]) {
                res.emplace_back("Push");
                res.emplace_back("Pop");
                i++;
            }
            res.emplace_back("Push");
            i++;
            p++;
        }
        return res;
    }
};
// @lc code=end

