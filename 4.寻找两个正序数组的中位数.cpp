/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int findKth(vector<int>& nums1, int start1, int end1, vector<int>& nums2, int start2, int end2, int k) {

        if (start1 > end1)
            return nums2[start2 + k - 1];
        if (start2 > end2)
            return nums1[start1 + k - 1];
        if (k == 1) {
            return min(nums1[start1], nums2[start2]);
        }

        int mid1 = min(k / 2 + start1 - 1, end1);
        int mid2 = min(k / 2 + start2 - 1, end2);

        int len1 = mid1 - start1 + 1;
        int len2 = mid2 - start2 + 1;

        // len1 <= k / 2 len2 <= k / 2
        // 这里一个自然的想法是也可以构造 len1 >= k / 2 len2 >= k / 2 使得每次我们可以去掉某一个数组的头，但是这样会遇到一种情况无法处理，即算出来的 mid 越界，此时越界后需要回撤到不越界的地方，也就违背了对 len 的约束


        if (nums1[mid1] < nums2[mid2]) {
            // [xxxx|0000]
            // [0000|0000]
            // kth will not be in nums1[:mid1 + 1] because there are only <= k / 2 - 1 + k / 2 - 1 elements blow nums1[mid1]
            int newK = k - len1;
            return findKth(nums1, mid1 + 1, end1, nums2, start2, end2, newK);
        } else {
            // [0000|0000]
            // [xxxx|0000]
            int newK = k - len2;
            return findKth(nums1, start1, end1, nums2, mid2 + 1, end2, newK);
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size = nums1.size() + nums2.size();
        if (size % 2 == 0) {
            int mid1 = size / 2;
            int mid2 = mid1 + 1;
            int mid1th = findKth(nums1, 0, nums1.size() - 1, nums2, 0, nums2.size() - 1, mid1);
            cout << mid1th << endl;
            int mid2th = findKth(nums1, 0, nums1.size() - 1, nums2, 0, nums2.size() - 1, mid2);
            cout << mid2th << endl;
            return ((double)mid1th + (double)mid2th) / 2;
        } else {
            int mid = size / 2 + 1;
            return findKth(nums1, 0, nums1.size() - 1, nums2, 0, nums2.size() - 1, mid);
        }
    }
};
// @lc code=end

