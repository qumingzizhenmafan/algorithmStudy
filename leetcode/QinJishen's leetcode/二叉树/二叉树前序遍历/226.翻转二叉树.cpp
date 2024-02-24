/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
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
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

class Solution {
public:
  TreeNode *invertTree(TreeNode *root) {
    if (root == nullptr) return root;
    swap(root->left, root->right);
    invertTree(root->left);
    invertTree(root->right);
    return root;
  }
};

/**
 * @details 迭代法前序遍历
 * 
 */
class SolutionRecursion : public Solution {
public:
  TreeNode *invertTree(TreeNode *root) {
    if (root == nullptr)
      return nullptr;

    std::queue<TreeNode *> que;
    que.push(root);
    while (!que.empty()) {
      TreeNode *node = que.front();
      que.pop();
      que.push(node->right);
    }

    return root;
  }
};

// @lc code=end
