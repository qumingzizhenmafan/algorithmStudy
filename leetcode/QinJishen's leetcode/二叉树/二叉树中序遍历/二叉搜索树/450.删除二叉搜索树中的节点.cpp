/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] 删除二叉搜索树中的节点
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

/**
 * @brief 
 * * 1. 没找要删除的节点
 * * 2. 叶子节点: 左右均为空
 * * 3. 删除的节点左不为空且右为空
 * * 4. 删除的节点左为空且右不为空
 * * 5. 删除的节点左右均不为空
 */
class Solution {
public:
    //* 递归
    TreeNode* deleteNode(TreeNode* root, int key) {
        //* 终止条件
        if (root == nullptr) return root;
        if (root->val == key){
            if (root->left == root->right){
                delete root;
                return nullptr;
            }
            else if (root->left != nullptr && root->right == nullptr)
            {
                auto resNode = root->left;
                delete root;
                return resNode;
            }
            else if (root->left == nullptr && root->right != nullptr)
            {
                auto resNode = root->right;
                delete root;
                return resNode;
            }
            else
            {
                TreeNode* cur = root->right;
                while (cur->left != nullptr)
                {
                    cur = cur->left;
                }
                cur->left = root->left;
                auto resNode = root->right;
                delete root;
                return resNode;
            }
        }


        //* 单层递归逻辑
        if (root->val > key) root->left = deleteNode(root->left, key);
        if (root->val < key) root->right = deleteNode(root->right, key);

        return root;
    }
};
// @lc code=end















TreeNode* deleteNode(TreeNode* root, int key) {
        
        //* 终止条件
        if (root == nullptr) return root;
        if (root->val == key){
            if (root->left == nullptr && root->right == nullptr) {
                delete root;
                return nullptr;
            }
            else if (root->left != nullptr && root->right == nullptr) {
                auto retNode = root->left;
                delete root;
                return retNode;
            }
            else if (root->left == nullptr && root->right != nullptr) {
                auto retNode = root->right;
                delete root;
                return retNode;
            }
            else
            {
                TreeNode* cur = root->right;
                while(cur->left != nullptr) {
                    cur = cur->left;
                }
                cur->left = root->left;
                auto retNode = root->right;
                delete root;
                return retNode;
            }
        }

        //* 单层递归逻辑
        if (root->val > key) root->left = deleteNode(root->left, key);
        if (root->val < key) root->right = deleteNode(root->right, key);

        return root;
    }