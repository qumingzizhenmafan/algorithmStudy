/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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
  * @attention 递归三部曲
  * 1. 确定传入参数
  * 2. 确定终止条件
  * 3. 
  */
#include <string>
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }

        vector<string> result;
        vector<int> path;
        traversal(root, path, result);

        return result;
    }

    void traversal(TreeNode* node, vector<int>& path, vector<string>& result){
        path.push_back(node->val);
        if(node->left == nullptr && node->right == nullptr){
            string ch = "";
            string arrow = "->";
            for(int& num : path){
                ch += std::to_string(num) + arrow;
            }
            ch.pop_back();
            ch.pop_back();
            result.push_back(ch);
            return;
        }

        if(node->left != nullptr) {
            traversal(node->left, path, result);
            path.pop_back();
        }
        if(node->right != nullptr) {
            traversal(node->right, path, result);
            path.pop_back();
        }
    }
};
// @lc code=end

