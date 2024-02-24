/*
 * @lc app=leetcode.cn id=513 lang=cpp
 *
 * [513] 找树左下角的值
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
 * @brief 迭代法(层序遍历)找树左下角的值
 * 
 */
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        if (root == nullptr) return 0;
        int res = 0;
        queue<TreeNode *> que;
        que.push(root);

        while(!que.empty()){
            TreeNode* node = que.front();
            que.pop();
            if(node->left == nullptr && node->right == nullptr)
                res = node->val;

            if(node->right != nullptr) que.push(node->right);
            if(node->left != nullptr) que.push(node->left);
        }

        return res;
    }
};
// @lc code=end

/**
 * @brief 递归法解决最左下角的值
 * 1.传入参数 
 * 2.终止条件
 * 3.单层递归的逻辑
 */
 int findBottomLeftValue(TreeNode* root) {
    int maxDepth = INT_MIN;
    int result;
 }

 void traversal(TreeNode* root, int depth){
    // 叶子节点
    if(root->left == nullptr && root->right == nullptr)
        if(depth > maxDepth) {
            maxDepth = depth;
            result = root->val;
        }

/**
 *  @brief 遍历代码等效于
 *  if(root->left){
 *   traversal(root->left, depth + 1);
 *  }
 */
    // 遍历左侧
    if(root->left){
        depth++;
        traversal(root->left, depth);
        depth--; // 回溯
    }


    // 遍历右侧
    if(root->right){
        depth++;
        traversal(root->right, depth);
        depth--; // 回溯
    }
 }
