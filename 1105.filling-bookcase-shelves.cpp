/*
 * @lc app=leetcode.cn id=1105 lang=cpp
 *
 * [1105] Filling Bookcase Shelves
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        // dp[i] 表示前 i 本书进行分组情况下的最小高度
        int n = books.size();
        vector<int> dp(n + 1);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            int max_h = books[i - 1][1];
            int sum_w = books[i - 1][0];
            dp[i] = dp[i - 1] + max_h;
            for (int j = i - 2; j >= 0; j++) {
                sum_w += books[j][0];
                if (sum_w <= shelfWidth) {
                    max_h = max(max_h, books[j][1]);
                    dp[i] = min(dp[i], dp[j] + max_h);
                } else {
                    break;
                }
            }
        }
        return dp[n];
    }
};
// @lc code=end

