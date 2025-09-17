/*
 * @lc app=leetcode.cn id=3633 lang=cpp
 *
 * [3633] Earliest Finish Time for Land and Water Rides I
 */

#include <climits>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();
        int min_t = INT_MAX;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                min_t = min(min_t, max(landStartTime[i] + landDuration[i] + waterDuration[j], waterStartTime[j] + waterDuration[j]));
                min_t = min(min_t, max(waterStartTime[j] + waterDuration[j] + landDuration[i], landStartTime[i] + landDuration[i]));
            }
        }
        return min_t;
    }
};
// @lc code=end

