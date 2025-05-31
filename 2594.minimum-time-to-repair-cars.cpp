/*
 * @lc app=leetcode.cn id=2594 lang=cpp
 *
 * [2594] Minimum Time to Repair Cars
 */

#include <climits>
#include <numeric>
#include <vector>
#include <cmath>

using namespace std;

// @lc code=start
class Solution {

    long long repaired(vector<int>& ranks, long long time) {
        return accumulate(ranks.begin(), ranks.end(), 0LL, [&](long long res, int rank){
            return res + sqrt(time / rank);
        });
    }

public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long minRank = accumulate(ranks.begin(), ranks.end(), INT_MAX, [](int minVal, int curr) { return min(minVal, curr); });
        long long maxRank = accumulate(ranks.begin(), ranks.end(), 0, [](int maxVal, int curr) { return max(maxVal, curr); } );
        
        // 使用二分搜索查找刚刚能修好的时间点，最小是 1，最大需要寻找边界
        long long l = 1;
        long long averCar = ceil((double) cars / ranks.size());
        long long r = min((long long)cars * cars * minRank, averCar * averCar * maxRank);
        while (l < r) {
            // invariant: r time can fix cars
            long long mid = l + (r - l) / 2;
            if (repaired(ranks, mid) < cars) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return r;
    }
};
// @lc code=end

