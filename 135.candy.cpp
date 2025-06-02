/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] Candy
 */

#include <climits>
#include <numeric>
#include <vector>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    int candy(vector<int>& ratings) {
        // 可以使用贪心，一个评分较高（某个山顶）的小孩分到的糖果树，制约于到达这个山顶的山坡的长度。
        // 从左往右看，从山底到山顶时，我们尽可能少增长，每次只多给一个糖果，而经过山顶后，如果下坡的长度小于上坡，那么尽快降为 1 即可，肯定不会制约山顶的最小高度。
        // 因此，“山顶”的高度制约于两侧上坡的长度，取最大值，所以分别从左侧和右侧遍历一次就可以知道每个位置需要多少糖果，取其较大的一个
        // 有点像接水题

        vector<int> candies(ratings.size());
        int length = 0;
        int prev = INT_MAX;
        for (int i = 0; i < ratings.size(); i++) {
            if (prev >= ratings[i]) {
                candies[i] = 1;
                length = 1;
            } else {
                length++;
                candies[i] = length;
            }
            prev = ratings[i];
        } 

        length = 0;
        prev = INT_MAX;

        for (int i = ratings.size() - 1; i >= 0; i--) {
            if (prev >= ratings[i]) {
                candies[i] = max(candies[i], 1);
                length = 1;
            } else {
                length++;
                candies[i] = max(candies[i], length);
            }
            prev = ratings[i];
        }

        return accumulate(candies.begin(), candies.end(), 0);
    }
};
// @lc code=end

