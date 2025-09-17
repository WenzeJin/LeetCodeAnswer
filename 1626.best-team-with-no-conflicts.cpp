/*
 * @lc app=leetcode.cn id=1626 lang=cpp
 *
 * [1626] Best Team With No Conflicts
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        // 本质上就是求权值最大递增序列，这里的递增在年龄不严格递增的情况下，分数不严格递增。注意同年龄的分数可以有大小。所以我们同年龄时，分数按递增排序，这样就可以直接使用套用 LIS。
        int n = scores.size();
        vector<int> index(n);
        for (int i = 0; i < n; i++) {
            index[i] = i;
        }

        sort(index.begin(), index.end(), [&](int x, int y) -> bool {
            if (ages[x] < ages[y]) {
                return true;
            } else if (ages[x] == ages[y]) {
                return scores[x] < scores[y];
            }
            return false;
        });

        vector<int> dp(n);
        for (int i = 0; i < n; i++) {
            int score = scores[index[i]];
            dp[i] = score;
            for (int j = 0; j < i; j++) {
                if (scores[index[j]] <= score) {
                    dp[i] = max(dp[i], dp[j] + score);
                }
            }
        }

        int max_s = 0;
        for (int s: dp) {
            max_s = max(max_s, s);
        }

        return max_s;
    }
};
// @lc code=end

