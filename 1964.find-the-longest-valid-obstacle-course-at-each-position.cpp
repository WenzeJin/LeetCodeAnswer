/*
 * @lc app=leetcode.cn id=1964 lang=cpp
 *
 * [1964] Find the Longest Valid Obstacle Course at Each Position
 */

#include <climits>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        // 预先处理出每一位正向的 LIS，和反向的 LDS 就可以
        int n = obstacles.size();
        vector<int> lis(n);
        vector<int> s;
        s.push_back(INT_MIN);
        for (int i = 0; i < n; i++) {
            auto it = upper_bound(s.begin(), s.end(), obstacles[i]);
            if (it == s.end()) {
                lis[i] = s.size();
                s.push_back(obstacles[i]);
            } else {
                lis[i] = it - s.begin();
                *it = obstacles[i];
            }
        }

        vector<int> lds(n);
        s.clear();
        s.push_back(INT_MAX);
        auto cmp = [](int a, int b) {return a < b;};
        for (int i = n - 1; i >= 0; i++) {
            auto it = upper_bound(s.begin(), s.end(), obstacles[i], cmp);
            if (it == s.end()) {
                lis[i] = s.size();
                s.push_back(obstacles[i]);
            } else {
                lis[i] = it - s.begin();
                *it = obstacles[i];
            }
        }

        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] = lis[i] + lds[i] - 1;
        }

        return ans;

    }
};
// @lc code=end

