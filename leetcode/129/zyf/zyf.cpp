#include "../../stdc.h"
//129. 求根节点到叶节点数字之和
//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    int target = 0;
    void jisuan(int i, TreeNode* root){
        i = i * 10 + root->val;
        if(root->left == nullptr && root->right == nullptr) target += i;
        else{
            if(root->left) jisuan(i, root->left);
            if(root->right) jisuan(i , root->right);
        }
    }
public:
    int sumNumbers(TreeNode* root) {
        jisuan(0, root);
        return target;
    }
};