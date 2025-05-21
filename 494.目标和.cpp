/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */

// @lc code=start
#include <numeric>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
    int target;
    unordered_map<string, int> memo;
public:
    int dfs(vector<int>& nums, int index, int buffer) {
        if (index >= nums.size()) {
            if(buffer == target) {
                return 1;
            }
            return 0;
        }

        string key = to_string(index) + "," + to_string(buffer);
        if (memo.count(key)) {
            return memo[key];
        }


        return memo[key] = dfs(nums, index + 1, buffer + nums[index]) 
        + dfs(nums, index + 1, buffer - nums[index]);

    }

    int findTargetSumWays(vector<int>& nums, int target) {
        // this->target = target;
        // return dfs(nums,0,0);
        // 另一种做法，这道题实际上就是一个子集划分问题，一部分划入负集合，一部分划入正集合，而正集合+负集合为 sum, 正集合 - 负集合为 target, 所以正集合总和为 (sum + target) / 2 < sum 所以直接用一个 0 - 1 背包的 dp 就可以解决，令 dp[i][j] 为利用前 i 个数总和为 j 的表达式数目，dp[i][j] = dp[i - 1][j - nums[i]] + dp[i - 1][j + nums[i]]

        int sum = accumulate(nums.begin(), nums.end(), 0);

        if ((sum + target) % 2 != 0) {
            return 0;
        }
        
        int positive = (sum + target) / 2;
        if (positive < 0) {
            return 0;
        }

        vector<int> dp(positive + 1);
        dp[0] = 1;
        for (int i = 1; i <= nums.size(); i++) {
            for (int j = positive; j >= 0; j--) {
                // dp[j] = dp[j] old[i][j]
                if (j >= nums[i - 1]) {
                    dp[j] += dp[j - nums[i - 1]];
                }
            }
        }
        return dp[positive];
    }

    
};
// @lc code=end

