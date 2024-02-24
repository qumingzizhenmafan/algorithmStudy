/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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

/** 递归思路
 * void traversal(TreeNode* cur, vector<int>& res){
 *     if(cur == nullptr) return;
 *     traversal(cur->left, res);
 *     traversal(cur->right, res);
 *     res.push_back(cur->val);
 * }
*/

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> results;
//      traversal(root, results);
        stack<TreeNode*> st;

        if(root == nullptr)
            return {};

        st.push(root);
        while(!st.empty()){
            TreeNode* n = st.top();
            results.push_back(n->val);
            st.pop();
            if(n->left != nullptr) st.push(n->left);
            if(n->right != nullptr) st.push(n->right);
        }
        reverse(results.begin(), results.end());

        return results;
    }
};
// @lc code=end

