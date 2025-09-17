/*
 * @lc app=leetcode.cn id=2976 lang=cpp
 *
 * [2976] Minimum Cost to Convert String I
 */

#include <climits>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        // 根据题目要求，只需要将 source 按位转换为 target 就可以了，每一位的代价尽可能最小。
        // 用 floyd 算法预处理 a -> b 的最小转换代价。

        int n = original.size();
        vector<vector<int>> f(26, vector<int>(26, INT_MAX));
        
        for (int i = 0; i < n; i++) {
            f[original[i] - 'a'][changed[i] - 'a'] = min(f[original[i] - 'a'][changed[i] - 'a'], cost[i]);
        }

        for (int i = 0; i < 26; i++) {
            f[i][i] = 0;
        }

        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                if (f[i][k] == INT_MAX)
                    continue;
                for (int j = 0; j < 26; j++) {
                    if (f[k][j] != INT_MAX)
                        f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
                }
            }
        }

        long long ans = 0;
        for (int i = 0; i < source.length(); i++) {
            if (f[source[i] - 'a'][target[i] - 'a'] == INT_MAX) {
                return -1;
            }
            ans += f[source[i] - 'a'][target[i] - 'a'];
        }

        return ans;
        
    }
};
// @lc code=end

