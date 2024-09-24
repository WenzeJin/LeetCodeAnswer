# 169.Majority Element

[link](https://leetcode.com/problems/majority-element/)

这题可以用摩尔投票法来解决，摩尔投票法的核心思想是抵消，如果一个元素出现次数超过一半，那么它的出现次数减去其他元素的出现次数，最终一定是正数。所以可以用一个计数器来记录当前元素的出现次数，如果计数器为0，那么就换一个元素，最终剩下的元素就是出现次数超过一半的元素。

摩尔投票法的本质是，最终计票大于0，所以中途一旦出现票数为0的情况，就可以抛弃此前的数组，视作一个新的规模更小的问题，体现在算法实现中的操作就是更换major元素。

```C++
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int major = 1000000001;
        int cnt = 0;
        for(int x : nums){
            if(x == major) {
                cnt ++;
            } else {
                if(cnt == 0) {
                    major = x;
                    cnt = 1;
                } else {
                    cnt --;
                }
            }
        }
        return major;
    }
};
```