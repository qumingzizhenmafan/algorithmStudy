/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
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
class Solution {
public:
    int countNodes(TreeNode* root) {
        int count = 0;
        if (root == nullptr) return count;
        queue<TreeNode *> que;

        que.push(root);
        while(!que.empty()){
            TreeNode* node = que.front();
            count++;
            que.pop();
            if(node->left != nullptr) que.push(node->left);
            if(node->right != nullptr) que.push(node->right);
        }

        return count;
    }
};
// @lc code=end

