# Remove Duplicates from Sorted Array II

[link](https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/)

与[Remove Duplicates from Sorted Array](https://leetcode.com/problems/remove-duplicates-from-sorted-array/)类似，只是这次允许重复的元素最多出现两次。并且强制要求原地。引入状态机的思维，可以很容易解决这个问题。

```C++
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int state = 0;
        int current = -100000;
        int space = 0;
        int pt = 0;
        int len = nums.size();
        while(pt < len){
            if(nums[pt] != current) {
                state = 0;
                current = nums[pt];
                nums[space++] = nums[pt++];
            } else {
                if(state == 0) {
                    state = 1;
                    nums[space++] = nums[pt++];
                } else {
                    pt++;
                }
            }
        }
        return space;
    }
};
```

这里的状态机是一个简单的状态机，只有两个状态，一个是0，一个是1。如果当前元素与前一个元素相同，且状态为0，那么就可以继续添加这个元素，否则就跳过这个元素。这样就可以实现原地删除重复元素的目的。