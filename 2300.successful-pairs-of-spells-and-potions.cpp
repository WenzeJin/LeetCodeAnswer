/*
 * @lc app=leetcode.cn id=2300 lang=cpp
 *
 * [2300] Successful Pairs of Spells and Potions
 */

#include <functional>
#include <numeric>
#include <vector>

using namespace std;

// @lc code=start
/*
    可以使用双指针进行探索，spells 升序， potions 降序，开始移动。
    potions移动到第一个不能满足的位置，那么此前的potion都是可以满足的。

    对每一个 spell 进行二分搜索也可以，这两个方法的复杂度差不多，都受制于排序。
*/
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> idx(spells.size());
        iota(idx.begin(), idx.end(), 0);
        // 根据 spells 对 idx 进行排序
        sort(idx.begin(), idx.end(), [&](int a, int b) {
            return spells[a] < spells[b];
        });
        sort(potions.begin(), potions.end(), greater<int>());


        vector<int> res(spells.size());
        int pp = 0;
        for (int i: idx) {
            while (pp < potions.size() && (long long)spells[i] * potions[pp] >= success) {
                pp++;
            }
            res[i] = pp;
        }

        return res;
    }
};
// @lc code=end

