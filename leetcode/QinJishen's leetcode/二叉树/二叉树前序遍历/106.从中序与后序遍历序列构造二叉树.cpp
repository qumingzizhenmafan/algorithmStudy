/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
  * @brief 
  * 1.后序数组为0, 空节点
  * 2.后序数组的最后一个元素为根节点元素
  * 3.寻找中序数组位置作切割点
  * 4.切中序数组
  * 5.切后续数组
  * 6.递归处理左区间和右区间
  */
#include <algorithm>
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        //* if postorder.size == 0: return null
        if (postorder.size() == 0) { return nullptr; }

        //* get the value of the root
        int rootVal = postorder[postorder.size() - 1];
        TreeNode* root = new TreeNode(rootVal);

        //* 叶子节点
        //* 永远先返回叶子节点再对 postorder 进行 resize.
        if(postorder.size() == 1) return root;
        postorder.resize(postorder.size() - 1);

        //* find the split-point
        //? std::distance(small, big)
        int delimterIndex = std::distance(
            inorder.begin(), std::find(inorder.begin(), inorder.end(), rootVal));

        //* split the inorder
        //* [0, delimiterIndex)
        vector<int> leftInorder (inorder.begin(), inorder.begin() + delimterIndex);
        //* [delimiterIndex + 1, end)
        vector<int> rightInorder (inorder.begin() + delimterIndex + 1, inorder.end());

        //* split the postorder
        //* [0, leftInorder.size)
        vector<int> leftPostorder (postorder.begin(), postorder.begin() + leftInorder.size());
        //* [leftInorder.size, end)
        vector<int> rightPostorder (postorder.begin() + leftInorder.size(), postorder.end());
        
        //* traversal to build-tree
        root->left = buildTree(leftInorder, leftPostorder);
        root->right = buildTree(rightInorder, rightPostorder);

        return root;
    }
};
// @lc code=end
