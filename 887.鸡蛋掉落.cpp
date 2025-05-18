/*
 * @lc app=leetcode.cn id=887 lang=cpp
 *
 * [887] 鸡蛋掉落
 */

// @lc code=start
#include <climits>
#include <vector>

using namespace std;

class Solution {
    vector<vector<int>> dp;
public:
    int minOps(int k, int n) {
        if (dp[k][n] != INT_MAX) {
            return dp[k][n];
        }

        if (k == 1 || n == 1 || n == 0) {
            return dp[k][n] = n;
        }

        
        // 此处我们可以进行优化，由于我们是要找到 minOps(k, n - i) minOps(k - 1, i - 1) 最大值的最小值，而前者随 i 单调递减，（相同鸡蛋数，楼层少肯定尝试次数少），后者随 i 单调递增，所以我们就是要找到一个谷点
        // int min_op = INT_MAX
        // for (int i = 1; i <= n; i++) {
        //     min_op = min ( min_op, 
        //         max(minOps(k, n - i), minOps(k - 1, i - 1)) + 1
        //     );
        // }

        int lo = 1, hi = n;
        int res = INT_MAX;
        while(lo <= hi) {
            int mid = (lo + hi) / 2;
            int broken = minOps(k - 1, mid - 1);    // 单调递增
            int not_broken = minOps(k, n - mid);       // 单调递减
            if (broken > not_broken) {
                // 肯定要往左找
                hi = mid - 1;
                res = min(res,broken + 1);
            } else if (broken < not_broken) {
                // 肯定要往右找
                lo = mid + 1;
                res = min(res, not_broken + 1);
            } else {
                // 这就是谷点
                res = broken + 1;
                break;
            }
        }

        // 复杂度 O(KNlogN)
        return dp[k][n] = res;
    }


    int superEggDrop(int k, int n) {
        // 先从最基本的解法开始，定义二维 dp[i][j] 意义为，在 j 层中使用 i 个鸡蛋的最少搜索次数 j = 1 时，全为 1， i = 1 时，全为 j，因为每层都要试
        // dp = vector<vector<int>>(k + 1, vector<int>(n + 1, INT_MAX));

        // return minOps(k, n);

        // 进一步优化，修改 DP 数组的含义，dp[i][j] 的意义为，使用 i 个鸡蛋，j 次实验，最多能到达的楼层数。 dp[0][0] = 0; dp[1][j] = j;
        // dp[i][j] = 没碎向上 dp[i][j - 1] + 1 + dp[i - 1][j - 1] 碎了向下
        // 即我们的可探测层数是向两个方向增长的
        vector<long long> dpl(n + 1);
        // 由于只依赖上一层和这一层的，所以一维数组足够了
        for (int i = 1; i <= k; i++) {
            long long corner = dpl[0];
            for (int j = 1; j <= n; j++) {
                long long temp = dpl[j];
                dpl[j] = min(dpl[j - 1] + 1 + corner, (long long)INT_MAX); // corner = dp[i - 1][j - 1]
                corner = temp;
            }
        }

        for (int j = 1; j <= n; j++) {
            if (dpl[j] >= n) {
                return j;
            }
        }

        return n;
    }
};
// @lc code=end

