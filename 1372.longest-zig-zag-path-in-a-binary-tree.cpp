/*
 * @lc app=leetcode.cn id=1372 lang=cpp
 *
 * [1372] Longest ZigZag Path in a Binary Tree
 */

#include "lc_def.h"
#include <algorithm>

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
    int longest = 0;

    int longestHelper(TreeNode* root, int prev) {
        if (root == nullptr) {
            return 0;
        }

        int goLeft = longestHelper(root->left, 0) + 1;
        int goRight = longestHelper(root->right, 1) + 1;

        longest = max({longest, goLeft - 1, goRight - 1});

        return prev ? goLeft : goRight;
    }

public:
    int longestZigZag(TreeNode* root) {
        longestHelper(root, 0);
        return longest;
    }
};
// @lc code=end

