/*
 * @lc app=leetcode.cn id=2187 lang=cpp
 *
 * [2187] Minimum Time to Complete Trips
 */

#include <climits>
#include <numeric>
#include <vector>
#include <iostream>

using namespace std;

// @lc code=start
/*
    本题可以在一定的范围内二分查找所需的时间，因为能够完成的 trips 是随时间单调递增的，最少是 1 就可以完成。这里需要确定上界才能进行二分查找，可以得知 totalTrips * min(time) 或者 (totalTrips / n + 1 ) * max(time) 内肯定能完成 
*/
class Solution {

    long long trips(const vector<int>& time, long long totalTime) {
        return accumulate(time.begin(), time.end(), 0LL, [&](long long x, int y) {
            return x + totalTime / (long long)y;
        });
    }


public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long maxVal = accumulate(time.begin(), time.end(), 0, [](int maxVal, int x) {
            return max(maxVal, x);
        });
        long long minVal = accumulate(time.begin(), time.end(), INT_MAX, [](int minVal, int x) {
            return min(minVal, x);
        });
        int n = time.size();
        long long l = 1, r = min(minVal * totalTrips, maxVal * (totalTrips / n + 1));
        while (l < r) {
            // invariant: time r can manage totalTrips
            long long mid = l + (r - l) / 2;
            if (trips(time, mid) < totalTrips) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        
        return r;
    }
};
// @lc code=end

