/*
 * @lc app=leetcode.cn id=3439 lang=cpp
 *
 * [3439] Reschedule Meetings for Maximum Free Time I
 */

#include <vector>
#include <iostream>

using namespace std;

// @lc code=start

/*
    实际上就是我们可以最多整合 k + 1 个空闲时间，其实就是一个 k + 1 的滑动窗口，找空闲时间最大值。
*/
class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int window = 0;
        int maxVal = 0;
        int n = startTime.size();

        for (int i = 0; i <= n; i++) {
            if (i < k + 1) {
                int interval = (i == n ? eventTime : startTime[i]) - (i == 0 ? 0 : endTime[i - 1]);
                window += interval;
            } else {
                int old = i - k - 1;
                int newTime = (i == n ? eventTime : startTime[i]) - (i == 0 ? 0 : endTime[i - 1]) ;
                int oldTime = (old == n ? eventTime : startTime[old]) - (old == 0 ? 0 : endTime[old - 1]);
                window += newTime - oldTime;
            }

            if (i >= k) {
                maxVal = max(maxVal, window);
            }
        }

        return maxVal;
    }
};
// @lc code=end