/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start

#include <unordered_set>
#include <vector>

using namespace std;



class Solution {

    void dfs(vector<vector<int>>& answer, vector<int>& buffer, int first, int len) {
        if (first == len) {
            answer.emplace_back(buffer);
            return;
        }

        int i = first;
        unordered_set<int> used;
        while (i < len) {
            while (i < len && used.count(buffer[i])) {
                i++;
            }
            if (i == len) {
                break;
            }
            // 每一位的选择，对于每一个不同的数字，只能选择一次
            used.insert(buffer[i]);
            swap(buffer[i], buffer[first]);
            dfs(answer, buffer, first + 1, len);
            swap(buffer[i], buffer[first]);
            i++;
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> answer;
        dfs(answer, nums, 0, nums.size());
        return answer;
    }
};
// @lc code=end

