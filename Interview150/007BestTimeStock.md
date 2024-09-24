# 121.Best Time to Buy and Sell Stock

[link](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)

本题只要看出最大利润一定在当前值减去此前最小值中产生就行了。

```C++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        short min = 10001;
        short max = 0;
        for(int x: prices) {
            if(x < min) {
                min = x;
            }
            if(x - min > max){
                max = x - min;
            }
        }
        return max;
    }
};
```