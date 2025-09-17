/*
 * @lc app=leetcode.cn id=2522 lang=cpp
 *
 * [2522] Partition String Into Substrings With Values at Most K
 */

#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    int minimumPartition(string s, int k) {
        // 可以尽可能把划分划分到更远的位置（从左到右），假设某组划分，从某个划分开始，没有这么做，那么完全可以把这个划分移到更远的位置，且后面的划分只会更少或相同。
        long long win = 0;
        int slice = 0;
        for (char c: s) {
            win *= 10;
            win += c - '0';
            if (win > k) {
                // 需要在 c 前面添加一个划分，而如果 c 本身也比 k 大，那么就不能划分
                if (c - '0' > k) {
                    return -1;
                } else {
                    win = c - '0';
                    slice++;
                }
            }
        }
        return slice + 1;
    }
};
// @lc code=end

