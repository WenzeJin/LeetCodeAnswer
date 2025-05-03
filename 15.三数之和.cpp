/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

/*
    比较简单的一个题目，直接用一个哈希表记录某个数字是否出现过即可，当我们需要第三个数抵消前两个数的和时，我们查询这个数是否出现过，有哪几个位次出现过。
*/

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int, vector<int>> map;

        sort(nums.begin(), nums.end());

        // 遍历插入
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]].push_back(i);
        }

        vector<vector<int>> result;

        int i_prev = INT32_MIN;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == i_prev) {
                continue;
            } else {
                i_prev = nums[i];
            }

            int j_prev = INT32_MIN;
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[j] == j_prev) {
                    continue;
                } else {
                    j_prev = nums[j];
                }

                int need = -(nums[i] + nums[j]);
                if (map.contains(need)) {
                    for (int pos: map[need]) {
                        if (pos > i && pos > j) {
                            vector<int> res = {nums[i], nums[j], need};
                            result.push_back(res);
                            break;
                        }
                    }
                }
            }
        }
        return result;
    }
};
// @lc code=end

