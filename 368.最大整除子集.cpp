/*
 * @lc app=leetcode.cn id=368 lang=cpp
 *
 * [368] 最大整除子集
 */

// @lc code=start
#include <functional>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


class Solution {
    // vector<int> answer;
    // vector<int> buffer;
public:
    // void dfs(vector<int>& nums, int index) {
    //     if (index >= nums.size()) {
    //         if (buffer.size() > answer.size()) {
    //             answer = buffer;
    //         }
    //         return;
    //     }
        
    //     if (buffer.empty()) {
    //         // in
    //         buffer.push_back(nums[index]);
    //         dfs(nums, index + 1);
    //         buffer.pop_back();

    //         // not in
    //         dfs(nums, index + 1);
    //     } else {
    //         if (buffer.back() % nums[index] == 0) {
    //             buffer.push_back(nums[index]);
    //             dfs(nums, index + 1);
    //             buffer.pop_back();
    //         } else {
    //             dfs(nums, index + 1);
    //         }
    //     }

        
        
    // }


    vector<int> largestDivisibleSubset(vector<int>& nums) {
        // 要找最大整除子集，为了减少运算，我们可以先从大到小排序
        // 排序之后，即确定了整除运算的前后顺序，肯定是后面的整除前面的，前面的被整除
        // 之后，找到一个数学性质，如果 a % b = 0 => b % c = 0 则 a % c = 0, 即我们每次只需要比较集合中已加入的最后一个元素和待加入元素即可
        sort(nums.begin(), nums.end(), std::greater<int>());
        // dfs(nums, 0);
        // return answer;

        // 以上 dfs 版本 TLE，尝试 DP，因为实际上排序之后，就变成一个子序列问题
        vector<int> dp(nums.size(), 1);
        vector<int> sel(nums.size(), -1); // 保存选项用于回溯
        // dp[i] 表示以 nums[i] 结尾的子序列最长长度
        if (nums.size() == 1) {
            return nums;
        }

        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] % nums[i] == 0) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        sel[i] = j;
                    }
                }
            }
        }

        vector<int> res;
        int max_index = max_element(dp.begin(), dp.end()) - dp.begin();
        int curr = max_index;
        while (curr != -1) {
            res.push_back(nums[curr]);
            curr = sel[curr];
        }

        return res;
    }
};
// @lc code=end

