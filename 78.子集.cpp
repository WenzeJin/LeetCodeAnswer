/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
    vector<vector<int>> solution;
    vector<int> buffer;
public:
    void dfs(vector<int>& nums, int index) {
        if (index >= nums.size()) {
            solution.push_back(buffer);
            return;
        }

        // not in
        dfs(nums, index + 1);

        // in
        buffer.push_back(nums[index]);
        dfs(nums, index + 1);
        buffer.pop_back();
    }


    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(nums, 0);
        return solution;
    }
};
// @lc code=end

