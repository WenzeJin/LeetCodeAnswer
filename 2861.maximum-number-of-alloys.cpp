/*
 * @lc app=leetcode.cn id=2861 lang=cpp
 *
 * [2861] Maximum Number of Alloys
 */

#include <algorithm>
#include <vector>
#include <numeric>

using namespace std;

// @lc code=start
class Solution {
public:
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        int min_s = *min_element(stock.begin(), stock.end());
        int res = 0;
        // 由于所有的合金必须由同一台机器生产，所以枚举机器
        for (auto& comp: composition) {
            // 枚举答案，二分搜索答案，由于当 num 大于一定数量时由可以生产变为不能生产，所以可以二分
            auto check = [&](int num) {
                int money = 0;
                for (int i = 0; i < comp.size(); i++) {
                    money += max(0, comp[i] * num - stock[i]) * cost[i];
                    if (money > budget) {
                        return false;
                    }
                }
                return true;
            };


            int right = min_s + budget + 1;
            int left = 0; // left 始终可以
            while (left < right - 1) {
                int mid = left + (right - left) / 2;
                if (check(mid)) {
                    left = mid;
                } else {
                    right = mid;
                }
            }
            res = max(res, left);
        }

        return res;
    }
};
// @lc code=end

