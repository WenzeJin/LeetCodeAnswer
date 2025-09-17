/*
 * @lc app=leetcode.cn id=3635 lang=cpp
 *
 * [3635] Earliest Finish Time for Land and Water Rides II
 */

#include <climits>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        // 如果先玩陆地设施，那么应该结束的越早越好，求最早结束时间
        int minFinish1, minFinish2;
        minFinish1 = INT_MAX;
        for (int i = 0; i < landStartTime.size(); i++) {
            minFinish1 = min(minFinish1, landStartTime[i] + landDuration[i]);
        }
        // 再玩水上，每个水上的最早结束时间求出后，求出 minFinish2
        minFinish2 = INT_MAX;
        for (int i = 0; i < waterStartTime.size(); i++) {
            minFinish2 = min(minFinish2, max(minFinish1, waterStartTime[i]) + waterDuration[i]);
        }
        // 再考虑先玩水上的情况
        minFinish1 = INT_MAX;
        for (int i = 0; i < waterStartTime.size(); i++) {
            minFinish1 = min(minFinish1, waterStartTime[i] + waterDuration[i]);
        }
        for (int i = 0; i < landStartTime.size(); i++) {
            minFinish2 = min(minFinish2, max(minFinish1, landStartTime[i]) + landDuration[i]);
        } 
        return minFinish2;
    }
};
// @lc code=end

