# 27.移除元素

[题目链接](https://leetcode-cn.com/problems/remove-element/)

这题的关键问题是原地移除元素，用双指针解决问题即可。

```C++
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int space = 0;
        int pt = 0;
        int len = nums.size();
        while(pt < len) {
            if(nums[pt] != val){
                nums[space++] = nums[pt++];
            } else {
                pt++;
            }
        }
        return space;
    }
};
```