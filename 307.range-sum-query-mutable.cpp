/*
 * @lc app=leetcode.cn id=307 lang=cpp
 *
 * [307] Range Sum Query - Mutable
 */

#include <vector>

using namespace std;

// @lc code=start
class NumArray {
    vector<int> s;
    int n;

    void update(int o, int l, int r, int i, int val) {
        if (l == r) {
            s[o] = val;
            return;
        }

        int m = (l + r) / 2;
        if (i <= m) {
            update(o * 2, l, m, i, val);
        } else {
            update(o * 2 + 1, m + 1, r, i, val);
        }
        s[o] = s[o * 2] + s[o * 2 + 1];
    }

    int query(int o, int l, int r, int L, int R) {
        if (L <= l && r <= R) {
            return s[o];
        }

        int m = (l + r) / 2;
        int res = 0;
        if (L <= m) {
            res += query(o * 2, l, m, L, R);
        }
        if (R >= m + 1) {
            res += query(o * 2 + 1, m + 1, r, L, R);
        }
        return res;
    }

public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        s = vector<int>(4 * n);
        for (int i = 0; i < n; i++) {
            update(1, 0, n - 1, i, nums[i]);
        }
    }
    
    void update(int index, int val) {
        update(1, 0, n - 1, index, val);
    }
    
    int sumRange(int left, int right) {
        return query(1, 0, n - 1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
// @lc code=end

