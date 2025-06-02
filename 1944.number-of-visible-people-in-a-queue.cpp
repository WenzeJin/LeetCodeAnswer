/*
 * @lc app=leetcode.cn id=1944 lang=cpp
 *
 * [1944] Number of Visible People in a Queue
 */

#include <vector>
#include <stack>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        // 用单调栈就可以解决问题，单调栈中，每次要压入一个值时，其左侧的如果比它小，则可以看到他，且看不到后面的人，弹出，指导左侧的比他大，此时不弹出，但也可以看到他

        stack<int> ms;
        vector<int> res(heights.size());

        for (int i = 0; i < heights.size(); i++) {
            while (!ms.empty() && heights[ms.top()] < heights[i]) {
                res[ms.top()]++;
                ms.pop();
            }

            if (!ms.empty()) {
                res[ms.top()]++;
            }

            ms.push(i);
        } 

        return res;


    }
};
// @lc code=end

