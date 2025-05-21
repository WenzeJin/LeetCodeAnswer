/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
 */

#include "lc_def.h"
#include <climits>
#include <vector>

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

// 这题直接尝试用一个比较快的方法解决，从头到尾遍历一次，一个节点只有遇到下一个比它大的节点时才结束子树生成，成为下一个节点的左子树 O(n)

class Solution {
public:

    TreeNode* constructBelow(vector<int>& nums, int& pt, int max) {
        TreeNode* node = nullptr;

        while (pt < nums.size() && nums[pt] <= max) {
            node = new TreeNode(nums[pt], node, nullptr);
            pt++;
            node->right = constructBelow(nums, pt, node->val);
            // so the next is bigger than node->val
        }

        return node;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int pt = 0;
        return constructBelow(nums, pt, INT_MAX);
    }
};
// @lc code=end

