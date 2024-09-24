# 26.Remove Duplicates from Sorted Array

[link](https://leetcode.com/problems/remove-duplicates-from-sorted-array/)

同样，可以使用双指针实现原地删除重复元素。

```C++
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int current = -1000000;
        int space = 0;
        int pt = 0;
        int len = nums.size();
        while(pt < len){
            if(nums[pt] != current) {
                current = nums[pt];
                nums[space++] = nums[pt++];
            } else {
                pt++;
            }
        }
        return space;
    }
};
```