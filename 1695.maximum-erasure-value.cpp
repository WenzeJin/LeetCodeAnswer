/*
 * @lc app=leetcode.cn id=1695 lang=cpp
 *
 * [1695] Maximum Erasure Value
 */

#include <vector>
#include <unordered_set>

using namespace std;

// @lc code=start
/*
    非常简单的滑动窗口题目，找到和最大的互不相同子数组即可，用哈希表/集合记录是否存在某个元素，如果要加入一个新的已经存在的元素，必须缩小窗口直到没有这个元素为止。
*/
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> occur;
        int window = 0;
        int maxVal = 0;
        int lo = 0, hi = 0;
        while (hi < nums.size()) {
            if (occur.count(nums[hi])) {
                while (nums[lo] != nums[hi]) {
                    occur.erase(nums[lo]);
                    window -= nums[lo];
                    lo++;
                }
                occur.erase(nums[lo]);
                window -= nums[lo];
                lo++;
            }
            occur.insert(nums[hi]);
            window += nums[hi];
            hi++;

            maxVal = max(maxVal, window);
        }
        return maxVal;
    }
};
// @lc code=end

