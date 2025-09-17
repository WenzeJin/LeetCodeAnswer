/*
 * @lc app=leetcode.cn id=1504 lang=cpp
 *
 * [1504] Count Submatrices With All Ones
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        // 可以枚举上下边界，并统计其中高为 h 的数目
        int n = mat.size();
        int m = mat[0].size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            vector<int> h(m);
            for (int j = i; j < n; j++) {
                // 先统计这一行到 h 中
                int H = j - i + 1;
                for (int k = 0; k < m; k++) {
                    if (mat[j][k] == 1) {
                        h[k]++;
                    } else {
                        h[k] = 0;
                    }
                }
                int last = -1; // 最后一个非 h 位置
                for (int k = 0; k < m; k++) {
                    if (h[k] == H) {
                        ans += k - last;
                    } else {
                        last = k;
                    }
                }
            }
        }
        return ans;
    }
};
// @lc code=end

