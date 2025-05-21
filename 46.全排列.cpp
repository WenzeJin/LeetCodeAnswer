/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {

    void dfs(vector<vector<int>>& answer, vector<int>& buffer, int first, int len) {
        if (first == len) {
            answer.emplace_back(buffer);
        }
        
        // 将需要排列的数字移动到 first 位置，然后递归与回溯
        for (int i = first; i < len; i++) {
            swap(buffer[first], buffer[i]);
            dfs(answer, buffer, first + 1, len);
            swap(buffer[first], buffer[i]);
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> answer;
        dfs(answer, nums, 0, nums.size());
        return answer;
    }
};
// @lc code=end

