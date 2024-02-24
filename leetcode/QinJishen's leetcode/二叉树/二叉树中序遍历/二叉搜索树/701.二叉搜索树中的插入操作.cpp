/*
 * @lc app=leetcode.cn id=701 lang=cpp
 *
 * [701] 二叉搜索树中的插入操作
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
    //* 递归法
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        //* 递归终止条件
        if (root == nullptr){
            TreeNode* node = new TreeNode(val);
            root = node;
        }

        //* 这里的 root->left 和 root->right 代表着整个左子树和整个右子树
        if(root->val > val){
            root->left = insertIntoBST(root->left, val);
        }
        else if(root->val < val){
            root->right = insertIntoBST(root->right, val);
        }

        return root;
    }
};
// @lc code=end

    //* 迭代法
    TreeNode* insertIntoBST(TreeNode* root, int val) {       
        TreeNode* insertNode = new TreeNode(val);
            if(root == nullptr) return insertNode;

            TreeNode* cur = root;
            while(1){
                if (cur->val > val && cur->left != nullptr) cur = cur->left;
                else if (cur->val < val && cur->right != nullptr) {
                    cur = cur->right;
                }
                else break;
            }
            if (cur->val > val) cur->left = insertNode;
            else if (cur->val < val) cur->right = insertNode;
            
            return root;
    }