/*
 * @lc app=leetcode.cn id=3623 lang=cpp
 *
 * [3623] Count Number of Trapezoids I
 */

#include <vector>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int, long long> y_group;
        for (auto& p: points) {
            y_group[p[1]]++;
        }

        for (auto& kv: y_group) {
            kv.second = kv.second * (kv.second - 1) / 2;
        }

        long long res = 0;
        constexpr int MOD = 1e9 + 7;

        long long choice = 0;
        
        for (auto& kv: y_group) {
            res += choice * kv.second;
            res %= MOD;
            choice += kv.second;
        }


        return res;
    }
};
// @lc code=end

