/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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

// 递归思路
// void traversal(TreeNode* cur, vector<int>& res){
//     if(cur == nullptr) return;
//     traversal(cur->left, res);
//     res.push_back(cur->val);
//     traversal(cur->right, res);
// }

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode *> st;
        TreeNode *cur = root;

        while(cur != nullptr || !st.empty()){ //? "或"逻辑需要理解一下
            if(cur != nullptr) //! 左孩子不为空, 左孩子节点入栈
            {
                st.push(cur);
                cur = cur->left;
            }
            else               //! 左孩子为空, 处理中节点, 遍历右孩子
            {
                cur = st.top();
                st.pop();
                res.push_back(cur->val);
                cur = cur->right;
            }
        }

        return res;
    }
};
// @lc code=end

