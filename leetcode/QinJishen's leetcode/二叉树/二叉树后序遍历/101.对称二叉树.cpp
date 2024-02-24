/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
  bool isSymmetric(TreeNode *root) {
    bool res = compare(root);
    return res;
  }

  //! 递归 后续遍历
  bool compare(TreeNode *left, TreeNode *right) {
    if (left == nullptr && right != nullptr)
      return false;
    else if (left != nullptr && right == nullptr)
      return false;
    else if (left == nullptr && right == nullptr)
      return true;
    else if (left->val != right->val)
      return false;

    bool outside = compare(left->left, right->right);
    bool inside = compare(left->right, right->left);

    return (outside && inside) ? true : false;
  }
  //! 迭代 层序编译
  bool compare(TreeNode *root) {
      queue<TreeNode *> que;

      if (root != nullptr) que.push(root);

      while (!que.empty()) {
        int size = que.size();
        vector<int> v;

        for (int i = 0; i < size; i++) {
          TreeNode *node = que.front();
          que.pop();
          
          if (node == nullptr) {
            v.push_back(INT_MIN);
            continue;
          }
          else {
            v.push_back(node->val);
          }

          que.push(node->left);
          que.push(node->right);
        }

        int start = 0, end = size - 1;
        while (start < end) {
          if (v[start] != v[end])
            return false;
          start++;
          end--;
        }
      }

    return true;
  }
};
// @lc code=end
