/*
 * @lc app=leetcode.cn id=3373 lang=cpp
 *
 * [3373] Maximize the Number of Target Nodes After Connecting Trees II
 */

#include <vector>
#include <functional>

using namespace std;

// @lc code=start

/*
    对于奇偶数距离问题，只要在树上染色，相同颜色的数量就是偶数距离，对于另一颗树上的，取数量较大的颜色就可以，因为我们可以用连线的位置控制奇偶关系。
    要处理边界情况：另一颗树上只有一个节点，此时我们就不能随意连接了：如果本树上也只有一个节点，那么直接返回 1. 如果本树上有多个节点，那么这个节点就肯定可以被连成偶数长度。
    本树上只有一个节点，另一颗树上有多个节点，那么也是一样的，可以随意连接，控制奇偶数。
    而题目限制了点数都大于 2，所以不必考虑了。
*/
class Solution {
    vector<vector<int>> buildGraph(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> g(n);
        for (auto& e: edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        return g;
    }

    vector<char> colorGraph(vector<vector<int>>& g, int& c1, int& c2) {
        vector<char> color(g.size());
        function<void(int, char)> dfs = [&](int curr, char prev) {
            color[curr] = prev == 1 ? 2 : 1;
            if (color[curr] == 1) {
                c1++;
            } else {
                c2++;
            }
            for (int out: g[curr]) {
                if (!color[out]) {
                    dfs(out, color[curr]);
                }
            }
        };
        dfs(0,1);
        return color;
    }

public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        auto g = buildGraph(edges1);
        int c11 = 0, c12 = 0;
        auto c1 = colorGraph(g, c11, c12);
        

        g = buildGraph(edges2);
        int c21 = 0, c22 = 0;
        auto c2 = colorGraph(g, c21, c22);

        vector<int> answer;
        for (char color: c1) {
            if (color == 1) {
                answer.push_back(c11 + max(c21, c22));
            } else {
                answer.push_back(c12 + max(c21, c22));
            }
        }

        return answer;
    }
};
// @lc code=end

