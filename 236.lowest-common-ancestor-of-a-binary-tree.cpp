/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] Lowest Common Ancestor of a Binary Tree
 */
#include "lc_def.h"

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    TreeNode* lca(TreeNode* curr, TreeNode* p, TreeNode* q) {
        if (curr == nullptr || curr == p || curr == q) {
            return curr;    // curr is a candidate of lca
        }
        auto left = lca(curr->left, p, q);
        auto right = lca(curr->right, p, q);
        if (left == nullptr) {
            return right;
        } else if (right == nullptr) {
            return left;
        } else {
            return curr; // curr is a new lca candidate
        }
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return lca(root, p, q);
    }
};
// @lc code=end

