/*
 * @lc app=leetcode.cn id=1642 lang=cpp
 *
 * [1642] Furthest Building You Can Reach
 */

#include <climits>
#include <functional>
#include <numeric>
#include <vector>

using namespace std;

// @lc code=start
/*
    本题乍一看可以使用动态规划或记忆化搜索，即 dfs(curr, ladders, bricks) 表示当前位置用 ladders 和 bricks 最多可以到哪里。
    但实际上不用这么麻烦，因为 ladders 的使用是可以贪心的，只需要用在 bricks 使用最多的地方就可以了。
    所以我们枚举到达的点，看看给定 ladders 和 bricks 能否到达此处就可以了，判断时间是 O(n)，用二分查找，最终的时间复杂度就是 O(nlogn)。对于给定的 10^5 是完全足够的。
*/
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        auto check = [&](int pos) -> bool {
            vector<int> need;
            need.reserve(pos);
            int prev = INT_MAX;
            for (int i = 0; i <= pos; i++) {
                if (heights[i] > prev) {
                    need.push_back(heights[i] - prev);
                }
                prev = heights[i];
            }
            if (ladders >= need.size()) {
                return true;
            }
            sort(need.begin(), need.end(), greater<int>());
            auto it = need.begin() + ladders;
            int sumOfBricks = accumulate(it, need.end(), 0);
            return bricks >= sumOfBricks;
        };
        // invariant: l true, r false;
        int l = 0, r = heights.size();
        while (l + 1 < r) {
            int mid = l + (r - l) / 2 + 1;
            mid = mid == r ? r - 1: mid;
            if (check(mid)) {
                l = mid;
            } else {
                r = mid;
            }
        }
        return l;
    }
};
// @lc code=end

