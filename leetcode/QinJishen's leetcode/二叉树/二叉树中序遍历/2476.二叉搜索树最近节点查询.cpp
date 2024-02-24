/*
 * @lc app=leetcode.cn id=2476 lang=cpp
 *
 * [2476] 二叉搜索树最近节点查询
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
#include <functional>
#include <vector>
class Solution {
public:
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries) {
        
        std::vector<int> Values;
        std::function<void(TreeNode*)> dfs = [&](TreeNode* root) {
            if(!root) return;
            dfs(root->left);
            Values.push_back(root->val);
            dfs(root->right);
        };
        dfs(root);

        std::vector<std::vector<int>> answer;
        for(int q: queries){
            int maxi = -1, mini = -1;
            auto it = std::lower_bound(Values.begin(), Values.end(), q);
            if(it != Values.end()){
                maxi = *it;
                if (*it == q){
                    mini = *it;
                    answer.push_back({mini, maxi});
                    continue;
                }
            }
            if(it != Values.begin()){
                mini = *(--it);
            }
            answer.push_back({mini, maxi});
        }

        return answer;
    }
};
// @lc code=end

