/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
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
#include <climits>
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.size() == 0) return nullptr;

        //* get the maxValue
        int maxValue = INT_MIN;
        for(int num : nums){
            maxValue = (maxValue < num) ? num : maxValue;
        }

        //* get the maxIndex
        int maxIndex = 0;
        for(; maxIndex < nums.size(); maxIndex++){
            if(maxValue == nums[maxIndex]) break;
        }

        TreeNode* root = new TreeNode(maxValue);
        
        //* leave-node
        if(nums.size() == 0) return root;

        //*split left-nums
        vector<int> leftnums (nums.begin(), nums.begin() + maxIndex);
        //*split right-nums
        vector<int> rightnums (nums.begin() + maxIndex + 1, nums.end());

        //* traversal build-tree
        root->left = constructMaximumBinaryTree(leftnums);
        root->right = constructMaximumBinaryTree(rightnums);

        return root;

    }
};
// @lc code=end

