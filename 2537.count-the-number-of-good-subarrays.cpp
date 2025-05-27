/*
 * @lc app=leetcode.cn id=2537 lang=cpp
 *
 * [2537] Count the Number of Good Subarrays
 */

#include <vector>
#include <unordered_map>

using namespace std;

// @lc code=start
/*
    用哈希表统计目前窗口中相同数字的数目，若移入数字 k，原本k有 i 个，则会增加 i 对相同项
    每当右侧移动时，移动到第一个满足条件的位置，移动左侧到第一个即将不能满足条件的位置，那么统计左侧到 0 的距离，就是以右侧为边界时的子数组个数。
*/
class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int, int> window;
        int lo = 0, hi = 0;
        long long pairs = 0;
        long long cnt = 0;
        while (hi < nums.size()) {
            pairs += window[nums[hi]];
            window[nums[hi]]++;
            hi++;

            while (true) {
                if (pairs - (window[nums[lo]] - 1) < k) {
                    break; // 再移出就没法满足要求
                }
                window[nums[lo]]--;
                pairs -= window[nums[lo]];
                lo++;
            }

            if (pairs >= k) {
                cnt += lo + 1;
            }
        }
        return cnt;
    }
};
// @lc code=end

