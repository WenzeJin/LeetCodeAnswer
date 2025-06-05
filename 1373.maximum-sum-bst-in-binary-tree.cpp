/*
 * @lc app=leetcode.cn id=1373 lang=cpp
 *
 * [1373] Maximum Sum BST in Binary Tree
 */
#include "lc_def.h"
#include <algorithm>
#include <climits>

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

struct Info {
    int max;
    int min;
    int sum;
    bool isBST;
};

class Solution {
    
    int maxVal = 0;

    Info findAns(TreeNode* curr) {
        if (curr == nullptr) {
            return {INT_MIN, INT_MAX, 0, true};
        }

        auto left = findAns(curr->left);
        auto right = findAns(curr->right);

        int sum = left.sum + right.sum + curr->val;
        bool isBST = false;
        if (left.max < curr->val && right.min > curr->val && left.isBST && right.isBST) {
            maxVal = max(maxVal, sum);
            isBST = true;
        }

        return {
            max(left.max, max(right.max, curr->val)),
            min(left.min, min(right.min, curr->val)),
            sum,
            isBST
        };
    }

public:
    int maxSumBST(TreeNode* root) {
        findAns(root);
        return maxVal;
    }
};
// @lc code=end

