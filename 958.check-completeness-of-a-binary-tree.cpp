/*
 * @lc app=leetcode.cn id=958 lang=cpp
 *
 * [958] Check Completeness of a Binary Tree
 */

#include "lc_def.h" 
#include <climits>

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
    int depthRequire = INT_MIN;
    bool decreased = false;

    bool isComplete(TreeNode* curr, int depth) {
        if (curr == nullptr) {
            if (depthRequire == INT_MIN) {
                depthRequire = depth;
                return true;
            } else if (depthRequire == depth) {
                return true;
            } else if (depthRequire == depth + 1 && !decreased) {
                decreased = true;
                depthRequire = depth;
                return true;
            }
            return false;
        }

        return isComplete(curr->left, depth + 1) && isComplete(curr->right, depth + 1);
    }

public:
    bool isCompleteTree(TreeNode* root) {
        return isComplete(root, 0);
    }
};
// @lc code=end

