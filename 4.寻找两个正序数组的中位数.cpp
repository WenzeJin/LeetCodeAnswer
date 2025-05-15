/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
public:
    int findKth(vector<int>& nums1, int start1, int end1, vector<int>& nums2, int start2, int end2, int k) {
        if (start1 > end1)
            return nums2[start2 + k - 1];
        if (start2 > end2)
            return nums1[start1 + k - 1];

        int mid1 = (end1 + start1) / 2;
        int mid2 = (end2 + start2) / 2;
        int len1 = mid1 - start1 + 1;
        int len2 = mid2 - start2 + 1;

        if (len1 + len2 < k) {
            if (nums1[mid1] < nums2[mid2]) {
                // [xxxx|0000]
                // [0000|0000]
                int newK = k - len1;
                return findKth(nums1, mid1 + 1, end1, nums2, start2, end2, newK);
            } else {
                // [0000|0000]
                // [xxxx|0000]
                int newK = k - len2;
                return findKth(nums1, start1, end1, nums2, mid2, end2, newK);
            }
        } else {
            if (nums1[mid1] < nums2[mid2]) {
                // [0000|0000]
                // [0000|xxxx]
                return findKth(nums1, start1, end1, nums2, start2, mid2 - 1, k);
            } else {
                // [0000|xxxx]
                // [0000|0000]
                return findKth(nums1, start1, mid1 - 1, nums2, start2, end2, k);
            }
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size = nums1.size() + nums2.size();
        if (size % 2 == 0) {
            int mid1 = size / 2;
            int mid2 = mid1 + 1;
            int mid1th = findKth(nums1, 0, nums1.size() - 1, nums2, 0, nums2.size() - 1, mid1);
            int mid2th = findKth(nums1, 0, nums1.size() - 1, nums2, 0, nums2.size() - 1, mid2);
            return ((double)mid1 + (double)mid2) / 2;
        } else {
            int mid = size / 2 + 1;
            return findKth(nums1, 0, nums1.size() - 1, nums2, 0, nums2.size() - 1, mid);
        }
    }
};
// @lc code=end

