/*
 * @lc app=leetcode.cn id=2359 lang=java
 *
 * [2359] Find Closest Node to Given Two Nodes
 */

// @lc code=start

import java.util.Arrays;

/**
 * 这个题目实际上直接可以用两次 bfs 解决，而此题正好每个点又只有一个出边，所以 DFS 也是一样的
 */
class Solution {

    private void dfs(int[] edges, int[] dist, int node, int d) {
        dist[node] = d;
        if (edges[node] != -1 && dist[edges[node]] == -1) {
            dfs(edges, dist, edges[node], d + 1);
        }
    }

    public int closestMeetingNode(int[] edges, int node1, int node2) {
        int[] dist1 = new int[edges.length];
        int[] dist2 = new int[edges.length];
        Arrays.fill(dist1, -1);
        Arrays.fill(dist2, -1);
        dfs(edges, dist1, node1, 0);
        dfs(edges, dist2, node2, 0);
        int minDist = Integer.MAX_VALUE;
        int minIndex = -1;
        for (int i = 0; i < edges.length; i++) {
            if (dist1[i] == -1 || dist2[i] == -1) {
                continue;
            }
            if (Math.max(dist1[i],dist2[i]) < minDist) {
                minDist = Math.max(dist1[i], dist2[i]);
                minIndex = i;
            }
        }
        return minIndex;
    }
}
// @lc code=end

