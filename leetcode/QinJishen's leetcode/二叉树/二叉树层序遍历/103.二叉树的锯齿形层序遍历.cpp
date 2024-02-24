/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
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
#include <algorithm>
#include <queue>
#include <vector>
class Solution {
public:
    std::vector<std::vector<int>> zigzagLevelOrder(TreeNode* root) {
        std::queue<TreeNode*> que;
        std::vector<int> path;
        std::vector<std::vector<int>> result;
        int cur_level = 0;

        if (root == nullptr) return result;

        //* 层序遍历逻辑
        que.push(root);
        while(!que.empty()){
            int size = que.size();
            while(size--){
                TreeNode* node = que.front();
                que.pop();
                path.push_back(node->val);
                if (node->left != nullptr){
                    que.push(node->left);
                }
                if (node->right != nullptr){
                    que.push(node->right);
                }
            }

            //* 奇数层翻转数组
            if (cur_level % 2 == 1){
                std::reverse(path.begin(), path.end());
            }
            result.push_back(path);
            path.clear(); // 清空数组
            cur_level++;
        }

        return result;
    }
};
// @lc code=end

