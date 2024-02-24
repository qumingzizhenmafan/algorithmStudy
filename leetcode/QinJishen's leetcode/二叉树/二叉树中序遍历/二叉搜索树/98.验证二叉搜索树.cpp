/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
class Solution {
public:
    TreeNode* pre = nullptr;
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) return true;
        bool left = isValidBST(root->left);

        if (pre != nullptr && pre->val >= root->val) return false;
        pre = root; //* 记录前一个节点

        bool right = isValidBST(root->right);
        return left && right;
    }
};
// @lc code=end

class Solution {
private:
    std::vector<int> vec;
    void traversal(TreeNode* root){
        if (root == nullptr) return ;
        traversal(root->left);
        vec.push_back(root->val);
        traversal(root->right);
    }
public:
    bool isValidBST(TreeNode* root) {
        vec.clear();
        traversal(root);
        for(int i = 1; i < vec.size(); i++){
            if (vec[i - 1] >= vec[i]) return false;
        }
        return true;
    }
};


class Solution {
public:
    long long maxValue = LONG_MIN;
    bool isValidBST(TreeNode* root) {
        if(root = nullptr) return true;
        bool left = isValidBST(root->left);
        
        if (root->val > maxValue) maxValue = root->val;
        else return false;

        bool right = isValidBST(root->right);

        return left && right;
    }
};

    TreeNode* pre = nullptr;
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) return true;
        bool left = isValidBST(root->left);

        if (pre != nullptr && pre->val >= root->val) return false;
        pre = root; //* 记录前一个节点

        bool right = isValidBST(root->right);
        return left && right;
    }