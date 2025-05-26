/*
 * @lc app=leetcode.cn id=904 lang=cpp
 *
 * [904] Fruit Into Baskets
 */

#include <vector>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int lo = 0, hi = 0;
        int maxVal = 0;
        unordered_map<int, int> baskets;
        while (hi < fruits.size()) {
            if (baskets.count(fruits[hi])) {
                baskets[fruits[hi]]++;
                hi++;
            } else {
                while (baskets.size() > 1 && lo < hi) {
                    baskets[fruits[lo]]--;
                    if (baskets[fruits[lo]] == 0) {
                        baskets.erase(fruits[lo]);
                    }
                    lo++;
                }
                baskets[fruits[hi]]++;
                hi++;
            }
            maxVal = max(maxVal, hi - lo);
        }

        return maxVal;
    }
};
// @lc code=end

