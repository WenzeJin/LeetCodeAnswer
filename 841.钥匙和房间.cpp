/*
 * @lc app=leetcode.cn id=841 lang=cpp
 *
 * [841] 钥匙和房间
 */

#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        // 实际上就是一个有向图，最终看是否能够从0遍历完所有点。

        vector<bool> visited(rooms.size(), false);
        function<void(int)> dfs = [&](int curr) {
            visited[curr] = true;
            for (int out: rooms[curr]) {
                if (!visited[out]) {
                    dfs(out);
                }
            }
        };
        dfs(0);
        return all_of(visited.begin(), visited.end(), [](bool x) {return x;});
    }
};
// @lc code=end

