# 88.合并两个有序数组

[题目链接](https://leetcode.cn/problems/merge-sorted-array/)

要注意`nums1`的长度预留了合并后的长度，如果能利用这部分空间，就可以避免开一个新的数组，从后往前合并即可。

```C++
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> nums;
        int p = m + n - 1;
        m --; n--;
        while(m >= 0 && n >= 0) {
            if(nums1[m] < nums2[n]) {
                swap(nums2[n--], nums1[p--]);
            } else {
                swap(nums1[m--], nums1[p--]);
            }
        }
        while(m >= 0) {
            swap(nums1[m--], nums1[p--]);
        }
        while(n >= 0) {
            swap(nums2[n--], nums1[p--]);
        }
    }
};
```