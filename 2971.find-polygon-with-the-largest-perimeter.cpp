/*
 * @lc app=leetcode.cn id=2971 lang=cpp
 *
 * [2971] Find Polygon With the Largest Perimeter
 */

#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        // 要使周长最长，就从长度最小的边开始选，因为任何一个不包含长度最小边的方案都可以把这条边加上。
        // 不断选，如果当前是满足条件的多边形，就更新最大值
        sort(nums.begin(), nums.end());
        long long perimeter = 0;
        int cnt = 0;
        bool valid = false;
        long long maxVal = -1;
        for (int l: nums) {
            cnt++;
            valid = perimeter > l && cnt > 2;
            perimeter += l;
            if (valid) {
                maxVal = perimeter;
            }
        }
        return maxVal;
    }
};
// @lc code=end

