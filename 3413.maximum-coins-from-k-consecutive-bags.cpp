/*
 * @lc app=leetcode.cn id=3413 lang=cpp
 *
 * [3413] Maximum Coins From K Consecutive Bags
 */

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

/*
    直接用遍历每一个位置不太可能，数据比较大，所以只能遍历 coins，此时就会有对齐的问题，每一次当我们不能完全包住两个端点时，到底是和右端点对齐还是和左端点对齐。分别做一次即可。
*/
// @lc code=start
class Solution {
public:
    long long maximum(vector<vector<int>>& coins, int k) {
        int lo = 0, hi = 0;
        long long window = 0;
        long long maxVal = 0;
        while (hi < coins.size()) {
            window += (long long)(abs(coins[hi][1] - coins[hi][0]) + 1) * (long long)coins[hi][2];
            while (abs(coins[hi][1] - coins[lo][1]) > k) {
                window -= (long long)(abs(coins[lo][1] - coins[lo][0]) + 1) * (long long)coins[lo][2];
                lo++;
            }

            // 计算未覆盖区域
            long long uncover = (long long)(abs(coins[hi][1] - coins[lo][0]) - k + 1) * (long long)coins[lo][2];
            uncover = max(uncover, 0LL);
            hi++;

            //cout << "window: " << window << " uncover: " << uncover << endl;

            maxVal = max(maxVal, window - uncover);
        }
        return maxVal;
    }


    long long maximumCoins(vector<vector<int>>& coins, int k) {
        sort(coins.begin(), coins.end(), [](const auto& a, const auto& b) {
            return a[0] < b[0];
        });

        long long res = maximum(coins, k);

        auto itl = coins.begin();
        auto itr = coins.end() - 1;
        while (itr - itl > 0) {
            iter_swap(itl, itr);
            itl++;
            itr--;
        }

        for (auto& c: coins) {
            swap(c[0], c[1]);
        }

        res = max(res, maximum(coins, k));

        return res;
    }
};
// @lc code=end

