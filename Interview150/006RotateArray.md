# 189.Rotate Array

[link](https://leetcode.com/problems/rotate-array/)

本题的关键是如何原地旋转数组，可以使用三次翻转的方法来解决这个问题。首先将整个数组翻转，然后将前k个元素翻转，最后将后n-k个元素翻转，就可以得到结果。要想到这个办法需要找一下规律。

```C++
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        k = k % len;
        int l = 0, r = len - 1;
        while(l < r) {
            swap(nums[l++], nums[r--]);
        }
        l = 0; r = k - 1;
        while(l < r) {
            swap(nums[l++], nums[r--]);
        }
        l = k; r = len - 1;
        while(l < r) {
            swap(nums[l++], nums[r--]);
        }
    }
};
```