/*
 * @lc app=leetcode.cn id=1423 lang=cpp
 *
 * [1423] Maximum Points You Can Obtain from Cards
 */

#include <climits>
#include <numeric>
#include <vector>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        // 从开头和结尾拿走最多 k 张卡牌，实际上就留下了 n - k 张卡牌
        // 这 n - k 张卡牌是连续的，也就形成了一个滑动窗口
        // 现在要使拿走的卡片最大，也就是留下的卡片最少

        int remaining = cardPoints.size() - k;
        int sum = accumulate(cardPoints.begin(), cardPoints.end(), 0);
        if (remaining == 0) {
            return sum;
        }

        int window = 0;
        int minVal = INT_MAX;
        for (int i = 0; i < cardPoints.size(); i++) {
            if (i < remaining) {
                window += cardPoints[i];
            } else {
                window += cardPoints[i] - cardPoints[i - remaining];
            }

            // check
            if (i >= remaining - 1) {
                minVal = min(minVal, window);
            }
        }

        return sum - minVal;
    }
};
// @lc code=end

