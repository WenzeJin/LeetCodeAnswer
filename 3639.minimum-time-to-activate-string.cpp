/*
 * @lc app=leetcode.cn id=3639 lang=cpp
 *
 * [3639] Minimum Time to Activate String
 */

#include <string>
#include <vector>
#include <set>

using namespace std;

// @lc code=start
class Solution {
public:
    int minTime(string s, vector<int>& order, int k) {
        // 关注每一次有新的 * 产生时，产生的新字符串数量。
        // 当第 i 位变成 * 时，其产生数量和 其前一个 j 和后一个 * k 有关，数量为他们之间且包含 i 的数量，为(i - j)*(k - i)，因为一旦越过，那么这个字符串在之前就已经被计算过了。
        // 如何快速地查找 j 和 k，并支持动态插入新的 i 呢，可以想到平衡二叉树，而 C++ 中的 set 就支持这一任务。
        set<int> star;
        int n = s.length();
        star.insert(-1);
        star.insert(n);
        // 加入两个伪 * 代表边界
        long long cnt = 0;
        for (int i = 0; i < n; i++) {
            long long a = order[i];
            long long m = *(--star.lower_bound(a));
            long long n = *star.upper_bound(a);
            cnt += (a - m) * (n - a);
            if (cnt >= k) {
                return i;
            }
            star.insert(a);
        }
        return -1;
    }
};
// @lc code=end

