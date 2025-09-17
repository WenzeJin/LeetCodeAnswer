/*
 * @lc app=leetcode.cn id=3478 lang=cpp
 *
 * [3478] Choose K Elements With Maximum Sum
 */

#include <vector>
#include <numeric>
#include <queue>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        // 首先要用 nums1 对 index 排序
        int n = nums1.size();
        vector<int> ind(n);
        iota(ind.begin(), ind.end(), 0);

        sort(ind.begin(), ind.end(), [&](int i, int j) { return nums1[i] < nums1[j]; });

        priority_queue<int, vector<int>, greater<int>> pq; // 构造小顶堆

        vector<long long> ans(n);
        long long s = 0;
        for (int i = 0; i < n; i++) {
            ans[ind[i]] = s;
            pq.push(nums2[ind[i]]);
            s += nums2[ind[i]];
            if (pq.size() > k) {
                s -= pq.top();
                pq.pop();
            }
        }

        return ans;
    }
};
// @lc code=end

