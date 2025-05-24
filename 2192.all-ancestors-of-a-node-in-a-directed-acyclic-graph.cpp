/*
 * @lc app=leetcode.cn id=2192 lang=cpp
 *
 * [2192] All Ancestors of a Node in a Directed Acyclic Graph
 */

#include <vector>
#include <set>

using namespace std;

// @lc code=start
class Solution {
    vector<vector<int>> answer;
    vector<vector<int>> gin;
    vector<bool> visited;

    void dfs(int curr) {
        if (visited[curr]) {
            return;
        }
        visited[curr] = true;
        set<int> ancestors; // 确保不重复且有序
        for (int in: gin[curr]) {
            if (!visited[in]) {
                dfs(in);
            }
            for (int a: answer[in]) {
                ancestors.insert(a);
            }
            ancestors.insert(in);
        }
        answer[curr] = vector<int>(ancestors.begin(), ancestors.end());
    }

public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        answer = vector<vector<int>>(n);
        gin = vector<vector<int>>(n);
        visited = vector<bool>(n);

        for (auto& e: edges) {
            gin[e[1]].push_back(e[0]);
        }

        for (int i = 0; i < n; ++i) {
            dfs(i);
        }

        return std::move(answer);
    }
};
// @lc code=end

