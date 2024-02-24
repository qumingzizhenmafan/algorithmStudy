/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
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
#include <vector>
class Solution {
public:
    int maxCount = 0;
    int count = 0;
    TreeNode* pre = nullptr;
    std::vector<int> result;
    vector<int> findMode(TreeNode* root) {
        traversal(root);
        return result;
    }

    void traversal(TreeNode* cur){
        if (cur == nullptr) return;
        traversal(cur->left);

        //* 统计单一元素出现频率
        if (pre == nullptr) count = 1;
        else if (pre->val == cur->val) count++;
        else count = 1;
        pre = cur;

        //* 当前状态下的众数
        if (count == maxCount) result.push_back(cur->val);
        if (count > maxCount){
            maxCount = count;
            result.clear();
            result.push_back(cur->val);
        }

        traversal(cur->right);
    }
};
// @lc code=end

