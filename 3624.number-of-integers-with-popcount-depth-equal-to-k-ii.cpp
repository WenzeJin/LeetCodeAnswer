/*
 * @lc app=leetcode.cn id=3624 lang=cpp
 *
 * [3624] Number of Integers With Popcount-Depth Equal to K II
 */

#include <vector>
#include <cassert>

using namespace std;

// @lc code=start
long long popcount(long long x) {
    long long p = 1;
    long long res = 0;
    while (p <= x) {
        res += (x & p) > 0;
        p <<= 1;
    }
    return res;
}

int get_cnt (long long x) {
    int cnt = 0;
    while (x != 1) {
        x = popcount(x);
        cnt++;
    }
    assert(cnt < 6);
    return cnt;
}

int pre_calc[51];

int init = []() {
    for (int i = 1; i <= 50; i++) {
        pre_calc[i] = get_cnt(i);
    }
    return 0;
}();

int get_cnt_with_pre(long long x) {
    int cnt = 0;
    while (x != 1) {
        if (x <= 50) {
            return cnt + pre_calc[x];
        }
        x = popcount(x);
        cnt++;
    }
    return cnt;
}


class Solution {
    

    vector<vector<int>> cnt;

    void update(int o, int l, int r, int i, int val) {
        // update nums[i]'s popcount to val;
        if (l == r) {
            for (int j = 0; j <= 5; j++) {
              cnt[o][j] = 0;
            }
            cnt[o][val] = 1;
            return;
        }
        int m = (l + r) / 2;
        if (i <= m) {
            update(o * 2, l, m, i, val);
        } else {
            update(o * 2 + 1, m + 1, r, i, val);
        }
        for (int j = 0; j <= 5; j++) {
            cnt[o][j] = cnt[o * 2][j] + cnt[o * 2 + 1][j];
        }
    }

    int query(int o, int l, int r, int L, int R, int K) {
        if (L <= l && r <= R) {
            return cnt[o][K];
        }
        int res = 0;
        int m = (l + r) / 2;
        if (L <= m) {
            res += query(o * 2, l, m, L, R, K);
        }
        if (m + 1 <= R) {
            res += query(o * 2 + 1, m + 1, r, L, R, K);
        }
        return res;
    }

public:
    vector<int> popcountDepth(vector<long long>& nums, vector<vector<long long>>& queries) {
        int n = nums.size();
        cnt = vector<vector<int>>(n * 4, vector<int>(6));
        for (int i = 0; i < n; i++) {
            update(1, 0, n - 1, i, get_cnt_with_pre(nums[i]));
        }

        vector<int> ans;

        for (auto& q: queries) {
            if (q.size() == 4) {
                ans.push_back(query(1, 0, n - 1, q[1], q[2], q[3]));
            } else {
                update(1, 0, n - 1, q[1], get_cnt_with_pre(q[2]));
            }
        }

        return ans;
    }
};
// @lc code=end

