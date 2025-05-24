/*
 * @lc app=leetcode.cn id=3068 lang=cpp
 *
 * [3068] 最大节点价值之和
 */


#include <climits>
#include <vector>


using namespace std;

// @lc code=start
class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        // 一个基本事实：如果一个数变换两次，那么变回自身
        // 对于树上的任何一个路径，如果我们反转这个路径（使用的边变成不使用的，不使用的边变成使用的）我们每次就可以同时对首尾两个元素进行操作，而中间不变
        // 即，我们可以一对对地选择是否变换，而保持其他数不变
        // 即，我们可以选择偶数个点进行变换，那么我们只要贪心地选择那些变换后会变大的数就可以了
        // 如果有奇数个可以变大的数，我们需要比较变大最少的和变少最大的，如果总体上依然变大，那么就可以操作
        long long res = 0;
        int cnt = 0; // 我们操作的数
        int mindif = INT_MAX; // 我们操作的数中最小的增量，如果最后操作了奇数个，那么需要减去这个增量

        for (int x: nums) {
            if (x <= (x ^ k)) {
                // 此处必须是带上等于，因为我们要能变换就变换，最后奇数个时去掉的那个才是最小增量
                res += x ^ k;
                ++cnt;
                mindif = min(mindif, (x ^ k) - x);
            } else {
                res += x;
                mindif = min(mindif, x - (x ^ k)); // 最后我们不仅可以少变换一个，也可以多变换一个 损失 x - x ^ k
            }
        }
        if (cnt % 2 == 0) {
            return res;
        } else {
            return res - mindif;
        }
    }
};
// @lc code=end

