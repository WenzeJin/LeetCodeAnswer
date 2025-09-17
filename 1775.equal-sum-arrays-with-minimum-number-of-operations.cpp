/*
 * @lc app=leetcode.cn id=1775 lang=cpp
 *
 * [1775] Equal Sum Arrays With Minimum Number of Operations
 */

#include <numeric>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        // 我们可以在一定范围内调整两个数组，那么这两个数组就有“上升空间”和“下沉空间”，计算两个数组的这样的空间，按每一位计算。最后，根据我们的调平需要，依次选择这样的空间（一个数组上升，一个数组下沉），从大到小，直到足够。
        int sum1 = accumulate(nums1.begin(), nums1.end(), 0);
        int sum2 = accumulate(nums2.begin(), nums2.end(), 0);
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        if (sum1 == sum2) {
            return 0;
        }
        auto& bigger = sum1 > sum2 ? nums1 : nums2;
        auto& smaller = sum1 > sum2 ? nums2 : nums1;
        auto pBig = bigger.rbegin();
        auto pSmall = smaller.begin();
        int cnt = 0;
        int space = 0;
        while (pBig != bigger.rend() || pSmall != smaller.end()) {
            if (pBig == bigger.rend()) {
                space += 6 - *pSmall;
                // 此处可以优化
                if (*pSmall == 6) {
                    pSmall = smaller.end();
                } else {
                    pSmall++;
                }
            } else if (pSmall == smaller.end()) {
                space += *pBig - 1;
                if (*pBig == 1) {
                    pBig = bigger.rend();
                } else {
                    pBig++;
                }
            } else {
                if (6 - *pSmall > *pBig - 1) {
                    space += 6 - *pSmall;
                    pSmall++;
                } else {
                    space += *pBig - 1;
                    pBig++;
                }
            }
            cnt++;
            if (space >= abs(sum1 - sum2)) {
                return cnt;
            }
        }
        return -1;
    }
};
// @lc code=end

