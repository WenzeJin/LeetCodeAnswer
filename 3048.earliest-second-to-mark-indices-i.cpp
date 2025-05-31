/*
 * @lc app=leetcode.cn id=3048 lang=cpp
 *
 * [3048] Earliest Second to Mark Indices I
 */

#include <algorithm>
#include <vector>

using namespace std;

// @lc code=start
class Solution {

    bool valid(vector<int>& nums, vector<int>& change, int time) {
        vector<bool> marked(nums.size());
        int available = time;
        // 从最后时间点开始遍历，贪心地使一个位置的清零动作尽可能地晚
        for (int i = time; i >= 1; i--) {
            available = min(i, available); // 可用的时间
            int index = change[i - 1];  // 需要清零的位置
            if (marked[index - 1]) continue;    // 如果已经遍历过了，跳过
            // 可用于清零的动作数
            if (nums[index - 1] > available - 1) {
                return false;
            }
            available -= nums[index - 1] + 1;
            marked[index - 1] = true;
        }
        return all_of(marked.begin(), marked.end(), [](bool x) { return x; });
    }

public:
    int earliestSecondToMarkIndices(vector<int>& nums, vector<int>& changeIndices) {
        // 二分搜索找答案，如何判断每个时间点是否能够标记成为关键
        // 注意下标初始是 1 使用开区间二分，不变式：l false r true
        int l = 0, r = changeIndices.size();
        if (!valid(nums, changeIndices, r)) {
            return -1;
        }
        while (l + 1 < r) {
            int mid = (l + 1 + r) / 2;
            if (valid(nums, changeIndices, mid)) {
                r = mid;
            } else {
                l = mid;
            }
        }
        return r;
    }
};
// @lc code=end

