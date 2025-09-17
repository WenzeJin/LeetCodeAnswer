/*
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] Serialize and Deserialize Binary Tree
 */

#include "lc_def.h"
#include <string>
#include <sstream>
#include <queue>
#include <deque>

using namespace std;

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
class Codec {

public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
        stringstream ss;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            if (node == nullptr) {
                ss << "n ";
            } else {
                ss << node->val << " ";
                q.push(node->left);
                q.push(node->right);
            }
        }

        // cout << ss.str() << endl;

        return ss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        deque<pair<TreeNode *, int>> q; // node, state
        if (data == "n ") {
            return nullptr;
        }

        stringstream ss(data);
        string temp;
        ss >> temp;
        TreeNode* node = new TreeNode(stoi(temp));
        auto root = node;
        q.emplace_back(node, 0);

        while(ss >> temp) {
            auto f = q.front();
            q.pop_front();
            node = temp == "n" ? nullptr : new TreeNode(stoi(temp));
            if (f.second == 0) {
                f.first->left = node;
                q.emplace_front(f.first, 1);
            } else if (f.second == 1) {
                f.first->right = node;
            }

            if (node != nullptr) {
                q.emplace_back(node, 0);
            }
        }

        return root;

    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end

