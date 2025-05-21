/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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

#include <vector>
//#include "lc_def.h"

using namespace std;

typedef vector<int> vi;

class Solution {
    TreeNode* buildTree(vi preorder, vi inorder, int pl, int pr, int il, int ir) {
        if (pl == pr) {
            // leaf
            return new TreeNode(preorder[pl]);
        }

        if (pl > pr) {
            return nullptr;
        }

        int v = preorder[pl];
        int lpl, lpr, lil, lir;
        for (int i = il; i <= ir; i++) {
            if (inorder[i] == v) {
                lir = i - 1;
            }
        }
        int len = lir - il;
        lpl = pl + 1; lpr = lpl + len; lil = il;
        auto leftTree = buildTree(preorder, inorder, lpl, lpr, lil, lir);

        lil = lir + 2;
        lir = ir; lpl = lpr + 1; lpr = pr;
        auto rightTree = buildTree(preorder, inorder, lpl, lpr, lil, lir);

        return new TreeNode(v, leftTree, rightTree);
    }
    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
};
// @lc code=end

