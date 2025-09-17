/*
 * @lc app=leetcode.cn id=3629 lang=cpp
 *
 * [3629] Minimum Jumps to Reach End via Prime Teleportation
 */

#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

// @lc code=start
// 预处理所有数的质因数

constexpr int MX = 1e6 + 1;

vector<int> prime_factors[MX];

int init = []{
    for (int i = 2; i < MX; i++) {
        if (prime_factors[i].empty()) {
            for (int j = i; j < MX; j += i) {
                prime_factors[j].push_back(i);
            }
        }
    }
    return 0;
}(); // 在 leetcode 上只预处理一次。

class Solution {
public:
    int minJumps(vector<int>& nums) {
        //处理好质因数后，就可以知道每个格子能够质数跳转的目标。
        // 如果正向跳转，需要保存每个指数能够跳转到的目标下标，空间复杂度大
        // 如果反向跳转，可以借助之前的质因数表，只需要保存每个指数所在的位置即可。
        unordered_map<int, vector<int>> pindex;
        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i];
            if (prime_factors[x].size() == 1) {
                pindex[x].push_back(i);
            }
        }

        int n = nums.size();
        queue<pair<int, int>> q;
        vector<bool> visit(n);
        q.emplace(n - 1, 0);
        visit[n - 1] = true;
        while (!q.empty()) {
            auto curr = q.front();
            q.pop();
            int i = curr.first;
            int d = curr.second;
            if (i == 0) {
                return d;
            }

            if (!visit[i - 1]) {
                q.emplace(i - 1, d + 1);
                visit[i - 1] = true;
            }
            if (i < n - 1 && !visit[i + 1]) {
                q.emplace(i + 1, d + 1);
                visit[i + 1] = true;
            }
            for (int p: prime_factors[nums[i]]) {
                auto it = pindex.find(p);
                if (it != pindex.end()) {
                    for (int j: it->second) {
                        if (!visit[j]) {
                            visit[j] = true;
                            q.emplace(j, d + 1);
                        }
                    }
                    pindex.erase(it);
                }
            }
        }
        return -1;
    }
};
// @lc code=end

