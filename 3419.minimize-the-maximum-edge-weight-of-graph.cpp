/*
 * @lc app=leetcode.cn id=3419 lang=cpp
 *
 * [3419] Minimize the Maximum Edge Weight of Graph
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        // 最小化最大值的题目，先想想能不能基于一次遍历完成？好像比较困难，而且题目复杂度给的比较宽裕，10^5 看起来像一个 nlogn，所以只需要用 n 时间验证，用 logn 时间查找即可。因为最大值超过一个阈值之后，肯定满足，小于一个阈值之后，肯定不满足。
        
    }
};
// @lc code=end

