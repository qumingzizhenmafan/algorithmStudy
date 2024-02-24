/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
  * @brief 一个二叉树每个节点的左右两个子树的高度差的绝对值不超过1
  * @details 使用递归后序(左右中)遍历, 从叶子开始求高度, 从根节点开始求深度
  */
class Solution {
public:
    int getHeight(TreeNode* node){
        if(node == nullptr) return 0;
        int leftHeight = getHeight(node->left);
        if(leftHeight == -1) return -1; // 左子树不满足AVL
        int rightHeight = getHeight(node->right);
        if(rightHeight == -1) return -1;// 右子树不满足AVL

        int result; 
        if(abs(rightHeight - leftHeight) > 1) result = -1;
        else{
            // 当前节点的最大高度取决于左右子树的最大高度
            result = 1 + max(rightHeight, leftHeight);
        }
        return result;
    }

    bool isBalanced(TreeNode* root) {
        int height = getHeight(root);
        if(height == -1) return false;
        return true;
    }
};
// @lc code=end

