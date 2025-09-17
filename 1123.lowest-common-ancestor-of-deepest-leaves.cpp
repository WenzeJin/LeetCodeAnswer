/*
 * @lc app=leetcode.cn id=1123 lang=cpp
 *
 * [1123] Lowest Common Ancestor of Deepest Leaves
 */

#include "lc_def.h"
#include <cstddef>
#include <functional>

using namespace std;

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int max_depth = 0;
        TreeNode *ans;
        function<int(TreeNode*, int)> dfs = [&](TreeNode* curr, int depth) -> int {
            if (curr == nullptr) {
                max_depth = max(max_depth, depth);
                return depth;
            }
            int ld = dfs(curr->left, depth + 1);
            int rd = dfs(curr->right, depth + 1);
            if (ld == rd && ld == max_depth) {
                ans = curr;
            }
            return max(ld, rd);
        };
        dfs(root, 0);
        return ans;
    }
};
// @lc code=end

