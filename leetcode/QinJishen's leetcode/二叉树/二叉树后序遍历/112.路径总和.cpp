/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) return false;
        return traversal(root, targetSum - root->val);
    }

    bool traversal(TreeNode* node, int target){
        if(node->left == nullptr && node->right == nullptr)
            return target == 0;

        if(node->left){
            if (traversal(node->left, target - node->left->val))
                return true;
        }

        if(node->right){
            target -= node->right->val;
            if(traversal(node->right, target)){
                return true;
            };
            target += node->right->val;
        }

        return false;
    }
};
// @lc code=end

bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) return false;

        queue<TreeNode* > que;
        int result = 0;
        que.push(root);
        while(!que.empty()){
            TreeNode* node = que.front();
            que.pop();

            result += node->val;
            if(result == targetSum) return true;
            if(node->left != nullptr && result + node->left->val <= targetSum){
                que.push(node->left);
            }
            if(node->right != nullptr && result + node->right->val <= targetSum){
                que.push(node->right);
            }
        }

        return false;
    }