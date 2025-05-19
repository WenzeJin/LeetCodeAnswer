/*
 * @lc app=leetcode.cn id=337 lang=cpp
 *
 * [337] 打家劫舍 III
 */

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
//#include "lc_def.h"

#include <unordered_map>

using namespace std;

class Solution {
    
public:
    // return <yes, no>
    std::pair<int, int> robOrNot(TreeNode *root) {
        int yes = root->val;
        int no = 0;
        if (root->left != nullptr) {
            auto left = robOrNot(root->left);
            yes += left.second;
            no += max(left.first, left.second);
        }

        if (root->right != nullptr) {
            auto right = robOrNot(root->right);
            yes += right.second;
            no += max(right.first, right.second);
        }

        return {yes, no};
    }

    int rob(TreeNode* root) {
        auto res = robOrNot(root);
        return max(res.first, res.second);
    }
};
// @lc code=end

