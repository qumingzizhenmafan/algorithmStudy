/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root) return {};

        stack<TreeNode*> st; //! 递归栈
        vector<int> results;
        st.push(root);
        while(!st.empty()){
            TreeNode* n = st.top();
            st.pop();
            results.push_back(n->val);                  //! 中
            if(n->right != nullptr) st.push(n->right);  //! 右
            if(n->left != nullptr) st.push(n->left);    //! 左
        }

        return results;
    }
};
// @lc code=end

