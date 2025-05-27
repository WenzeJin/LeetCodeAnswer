/*
 * @lc app=leetcode.cn id=1610 lang=cpp
 *
 * [1610] Maximum Number of Visible Points
 */

#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

// @lc code=start
/*
    计算出所有点到观测点的角度，然后用滑动窗口进行遍历就行了，这里需要注意头尾相接的问题，只需要将原有的角度再末尾加上 2 pi 再来一遍就可以了。
*/
class Solution {
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        int same = 0;
        vector<double> angles;
        for (auto& p: points) {
            if (p[0] == location[0] && p[1] == location[1]) {
                same++;
            } else {
                double angle = atan2(p[1] - location[1], p[0] - location[0]);
                angles.push_back(angle);
            }
        }

        sort(angles.begin(), angles.end());
        int s = angles.size();
        for (int i = 0; i < s; i++) {
            angles.push_back(angles[i] + 2 * M_PI);
        }

        int lo = 0, hi = 0;
        int arcAngle = (double) angle * M_PI / 180;
        int maxVal = 0;
        while (hi < angles.size()) {
            hi++;
            while (angles[hi - 1] - angles[lo] > arcAngle) {
                lo++;
            }
            maxVal = max(maxVal, hi - lo);
        }

        return maxVal + same;
    }
};
// @lc code=end

