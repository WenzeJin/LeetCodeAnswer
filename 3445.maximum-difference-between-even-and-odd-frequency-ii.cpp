/*
 * @lc app=leetcode.cn id=3445 lang=cpp
 *
 * [3445] Maximum Difference Between Even and Odd Frequency II
 */

#include <climits>
#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int maxDifference(string s, int k) {
        // 首先计算前缀和快速获取区间内 [l, r) 的字符数量
        vector<vector<int>> prefix(s.length() + 1, vector<int>(5));
        for (int i = 1; i <= s.length(); i++) {
            char c = s[i - 1];
            for (int j = 0; j < 5; j++) {
                if (c == j + '0') {
                    prefix[i][j] = prefix[i - 1][j] + 1;
                } else {
                    prefix[i][j] = prefix[i - 1][j];
                }
            }
        }

        // 先枚举出现奇数次和偶数次的数字组合。
        // 之后枚举区间 [l, r)，首先要满足以下限制条件
        // r - l >= k
        // 至少存在 x, y:
        // prefix[r][x] - prefix[l][x] > 0
        // prefix[r][y] - prefix[l][y] > 0
        // 且分别为奇偶，要找奇 - 偶的最大值

        // 如果固定 r 不动，那么 l 越靠左实际上越满足上述关系
        // 此时差值为 (rx - lx) - (ry - ly) = (rx - ry) - (lx - ly) 
        // 对每一个 l，找满足上述条件的 min(lx - ly) 这里要根据奇偶性需求的组合，分为四类，最后根据 rx 和 ry 的奇偶性进行选取。这样就可以让 l 一直向右推进，此时左侧的 min 都已经计算过了，不用再回头计算

        int maxVal = INT_MIN;
        for (int x = 0; x < 5; x++) {
            for (int y = 0; y < 5; y++) {
                if (x == y) {
                    continue;
                }

                // 枚举 r, 推进 l, minPre 表示此前最小的 lx - ly
                int minPre[2][2] = {INT_MAX, INT_MAX, INT_MAX, INT_MAX};
                int l = 0;
                for (int r = 1; r <= s.length(); r++) {
                    for (; l <= r - k; l++) {
                        if (prefix[r][x] == prefix[l][x] || prefix[r][y] == prefix[l][y]) {
                            break; // 需要下一个 r
                        }
                        int xOdd = prefix[l][x] % 2;
                        int yOdd = prefix[l][y] % 2;
                        minPre[xOdd][yOdd] = min(minPre[xOdd][yOdd], prefix[l][x] - prefix[l][y]);
                    }
                    int xOdd = prefix[r][x] % 2 == 0; // x需要奇数个，奇偶性相反
                    int yOdd = prefix[r][y] % 2;
                    if (minPre[xOdd][yOdd] != INT_MAX) {
                        maxVal = max(maxVal, (prefix[r][x] - prefix[r][y]) - minPre[xOdd][yOdd]);
                    }
                }
            }
        }
        return maxVal;
    }
};
// @lc code=end

