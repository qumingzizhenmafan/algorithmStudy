#include "C:\Users\12194\.leetcode\二叉树\BinaryTree.h"
#include <iostream>
/*
 * @lc app=leetcode.cn id=2583 lang=cpp
 *
 * [2583] 二叉树中的第 K 大层和
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
#include <utility>
#include <vector>
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        std::vector<long long> a;
        std::vector<TreeNode*> q = {root};
        while(!q.empty()){
            long long sum = 0;
            std::vector<TreeNode*> nxt;
            for(auto node : q){
                sum += node->val;
                if (node->left != nullptr) nxt.push_back(node->left);
                if (node->right != nullptr) nxt.push_back(node->right);
            }
            a.push_back(sum);
            q = move(nxt);
        }

        int n = a.size();
        if (k > n) { return -1; }

        //* C++20 Ranges库
        ranges::nth_element(a, a.begin() + (n - k));
        return a[n - k];
    }
};
// @lc code=end

int main(){
    Solution s;
    std::vector<int> nodes = {5, 8, 9, 2, 1, 3, 7, 4, 6};
    long long res = s.kthLargestLevelSum(buildTree(nodes), 2);
    std::cout << res << std::endl;
    return 0;
}