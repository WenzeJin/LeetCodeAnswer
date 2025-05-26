/*
 * @lc app=leetcode.cn id=1658 lang=cpp
 *
 * [1658] Minimum Operations to Reduce X to Zero
 */

#include <numeric>
#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
/*
    经典的拿左右开刀的题目，那么我们实际上就是要留下中间的窗口，其和为 sum - x，如果小了就放进来，如果大了就拿出去。最后我们要求的是最大窗口大小。
*/
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int target = sum - x;
        if (target < 0) {
            return -1;
        } else if (target == 0) {
            return nums.size();
        }
        int window = 0;
        int maxVal = 0;
        int lo = 0, hi = 0;
        while (hi < nums.size()) {
            window += nums[hi];
            hi++;

            while (window > target) {
                window -= nums[lo];
                lo++;
            }

            if (window == target) {
                maxVal = max(maxVal, hi - lo);
            }
        }

        return maxVal == 0 ? -1 : nums.size() - maxVal;
    }
};
// @lc code=end

