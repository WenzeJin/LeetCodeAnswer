/*
 * @lc app=leetcode.cn id=1298 lang=cpp
 *
 * [1298] Maximum Candies You Can Get from Boxes
 */

#include <vector>
#include <queue>

using namespace std;

// @lc code=start
class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        // BFS，当一个盒子即拥有本身，又拥有钥匙，就可以加入遍历队列
        int n = status.size();
        vector<bool> exposed(n);
        vector<bool> opened(n);
        
        for (int i = 0; i < status.size(); i++) {
            if (status[i] == 1) {
                opened[i] = true;
            }
        }

        for (int x: initialBoxes) {
            exposed[x] = true; 
        }

        vector<bool> visited(n);
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (exposed[i] && opened[i]) {
                q.push(i);
                visited[i] = true;
            }
        }

        int res = 0;

        while (!q.empty()) {
            int i = q.front();
            q.pop();
            res += candies[i];
            for (int k: keys[i]) {
                opened[k] = true;
                if (opened[k] && exposed[k] && !visited[k]) {
                    q.push(k);
                    visited[k] = true;
                }
            }
            for (int b: containedBoxes[i]) {
                exposed[b] = true;
                if (opened[b] && exposed[b] && !visited[b]) {
                    q.push(b);
                    visited[b] = true;
                }
            }
        }

        return res;
    }
};
// @lc code=end

