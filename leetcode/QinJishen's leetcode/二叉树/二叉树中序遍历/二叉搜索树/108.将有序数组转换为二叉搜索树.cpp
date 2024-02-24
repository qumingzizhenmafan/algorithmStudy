/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        //* 递归终止条件: 否则会指向错误
        if (nums.empty()) return nullptr;

        //* 单层递归条件, 寻找二分中点
        int midIndex = (0 + nums.size()) / 2;
        TreeNode* node = new TreeNode(nums[midIndex]);

        //* 拆分数组
        std::vector<int> leftNums(nums.begin(), nums.begin() + midIndex);
        std::vector<int> rightNums(nums.begin() + midIndex + 1, nums.end());

        //* 递归构造平衡二叉搜索树
        node->left = sortedArrayToBST(leftNums);
        node->right = sortedArrayToBST(rightNums);

        return node;
    }
};
// @lc code=end

