/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
#include <queue>
#include <vector>
class Solution {
public:
  vector<vector<int>> levelOrder(TreeNode *root) {
    if (root == nullptr)
      return {};

    vector<vector<int>> res;

    //! 广度优先搜索使用队列
    std::queue<TreeNode *> que;
    que.push(root);
    while (!que.empty()) {

      std::vector<int> v;
      int size = que.size();
      while (size--) {
        TreeNode* node = que.front();
        v.push_back(node->val);
        que.pop();
        if(node->left != nullptr) que.push(node->left);
        if(node->right != nullptr) que.push(node->right);
      }

      res.push_back(v);
    }

    return res;
  }
};
// @lc code=end








// queue<TreeNode *> que;
//     que.push(root);
//     while (!que.empty()) {
//       int size = que.size();
//       vector<int> vec;
//       while (size--) {
//         TreeNode *node = que.front();
//         que.pop();
//         vec.push_back(node->val);
//         if (node->left)
//           que.push(node->left);
//         if (node->right)
//           que.push(node->right);
//       }
//       res.push_back(vec);
//     }