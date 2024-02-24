#include "C:\Users\12194\.leetcode\二叉树\BinaryTree.h"
#include "C:\Users\12194\.leetcode\dp\print.h"
/*
 * @lc app=leetcode.cn id=889 lang=cpp
 *
 * [889] 根据前序和后序遍历构造二叉树
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
#include <iterator>
#include <vector>
class Solution {
public:
    TreeNode* constructFromPrePost(std::vector<int>& preorder, std::vector<int>& postorder) {
        //* 递归结束
        if (preorder.empty()) return nullptr;

        TreeNode* root = new TreeNode(preorder.front());

        //* 叶子节点
        if (preorder.size() == 1) return root;
        preorder.erase(preorder.begin());
        postorder.resize(postorder.size() - 1);

        //* delimiter member
        int delimiterValue = preorder.front();
        int delimiterIndex = std::distance(postorder.begin(), 
                std::find(postorder.begin(), postorder.end(), delimiterValue));

        std::vector<int> leftpost(postorder.begin(), postorder.begin() + delimiterIndex + 1);
        std::vector<int> rightpost(postorder.begin() + delimiterIndex + 1, postorder.end());

        std::vector<int> leftpre(preorder.begin(), preorder.begin() + leftpost.size());
        std::vector<int> rightpre(preorder.begin() + leftpost.size(), preorder.end());

        root->left = constructFromPrePost(leftpre, leftpost);
        root->right = constructFromPrePost(rightpre, rightpost);

        return root;
    }
};
// @lc code=end

int main(){
    Solution s;
    std::vector<int> preorder = {1,2,4,5,3,6,7};
    std::vector<int> postorder = {4,5,2,6,7,3,1};
    TreeNode* root = s.constructFromPrePost(preorder, postorder);
    print(getTreeValues(root));
    return 0;
}