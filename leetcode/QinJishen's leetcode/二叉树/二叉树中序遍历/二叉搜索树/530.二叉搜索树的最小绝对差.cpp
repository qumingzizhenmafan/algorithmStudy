/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
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

//! 求最小值使用 INT_MAX, 求最大值使用 INT_MIN
#include <algorithm>
#include <climits>
class Solution {
public:
    int result = INT_MAX; 
    TreeNode* pre = nullptr;
    int getMinimumDifference(TreeNode* root) {
        if (root == nullptr) return 0;

        getMinimumDifference(root->left);

        if (pre != nullptr){ 
            result = std::min(result, (root->val - pre->val));
        }
        pre = root;

        getMinimumDifference(root->right);

        return result;        
    }
};
// @lc code=end

