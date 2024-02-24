#include "二叉树/BinaryTree.h"
#include <vector>

/*
 * @lc app=leetcode.cn id=669 lang=cpp
 *
 * [669] 修剪二叉搜索树
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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        //* 递归终止条件
        if (root == nullptr) return root;
        
        if (root->val < low){
            TreeNode* right = trimBST(root->right, low, high); //* 继续遍历修剪而不是直接返回
            return right;
        }
        if (root->val > high){
            TreeNode* left = trimBST(root->left, low, high);   //* 继续遍历修剪而不是直接返回
            return left;
        }

        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);
        

        return root;
    }
};
// @lc code=end

int main(){
    Solution s;
    std::vector<int> tvec = {2, 1, 3};
    TreeNode* root = buildTree(tvec);
    root = s.trimBST(root, 1, 2);

    std::vector<int> res = getTreeValues(root);
    for(int n : res){
        std::cout << n << std::endl;
    }

    return 0;
}