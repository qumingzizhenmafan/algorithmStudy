/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
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
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == nullptr) return 0;
        int res = 0;
        queue<TreeNode* > que;
        que.push(root);
        while(!que.empty()){
            TreeNode* node = que.front();
            que.pop();
            if( node->left != nullptr &&
                node->left->left == nullptr && node->left->right == nullptr)
            {
                res += node->left->val;
            }

            if(node->left != nullptr) que.push(node->left);
            if(node->right != nullptr) que.push(node->right);
        }
        
        return res;
    }
};
// @lc code=end

/**
 * @brief 
 * 
 * @param node 
 * @return int 
 */
int traversal(TreeNode* node){
    if(node == nullptr) return 0;
    if(node->left == nullptr && node->right == nullptr) return 0;

    // left-tree 
    int leftNum = traversal(node->left);
    if( node->left != nullptr &&
        node->left->left == nullptr && node->left->right == nullptr)
    {
        int leftNum = node->left->val;
    }

    int rightNum = traversal(node->right);

    return leftNum + rightNum;
 }