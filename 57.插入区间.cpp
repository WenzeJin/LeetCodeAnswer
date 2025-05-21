/*
 * @lc app=leetcode.cn id=57 lang=cpp
 *
 * [57] 插入区间
 */

// @lc code=start

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // ri < ln 则新区间在旧区间右边
        // li > rn 则新区间在旧区间左边
        // 否则二者有重合，merge 成一个更大的区间

        vector<vector<int>> ans;
        vector<int> newInter = newInterval;
        bool inserted = false;
        for (auto& inter: intervals) {
            if (inter[1] < newInter[0]) {
                ans.push_back(inter);
            } else if (inter[0] > newInter[1]) {
                if (!inserted) {
                    ans.push_back(newInter);
                    inserted = true;
                }
                ans.push_back(inter);
            } else {
                newInter[0] = min(inter[0], newInter[0]);
                newInter[1] = max(inter[1], newInter[1]);
            }
        }
        if (!inserted) {
            ans.push_back(newInter);
        }
        return ans;
    }
};
// @lc code=end

