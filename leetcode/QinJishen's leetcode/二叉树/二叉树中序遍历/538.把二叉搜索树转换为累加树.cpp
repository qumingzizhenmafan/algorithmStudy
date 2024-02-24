/*
 * @lc app=leetcode.cn id=538 lang=cpp
 *
 * [538] 把二叉搜索树转换为累加树
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
    int count = 0;
    TreeNode* convertBST(TreeNode* root) {
        if (root == nullptr) return root;

        //* 右中左遍历
        if (root->right != nullptr) root->right = convertBST(root->right);

        count += root->val;
        std::cout << "count is: " << count << std::endl;
        root->val = count;

        if (root->left != nullptr) root->left = convertBST(root->left);

        return root;
    }
};
// @lc code=end

