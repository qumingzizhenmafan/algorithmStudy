/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 */

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

/**
  * @brief 
  * 后序遍历: 左右中
  */
//TODO 重新解决
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
    }
};
// @lc code=end
























if (root == nullptr) return root;
        if (root == p || root == q) return root;

        //* 后序递归
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        //* 找到目标公共祖先
        if(left != nullptr && right != nullptr) return root;

        //* 回溯过程
        if(left == nullptr && right != nullptr) return right;       //* 右子树包含目标节点
        else if (left != nullptr && right == nullptr) return left;  //* 左子树包含目标节点
        else return nullptr;