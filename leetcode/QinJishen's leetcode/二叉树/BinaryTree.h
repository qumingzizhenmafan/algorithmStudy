#include <climits>
#include <iostream>
#include <queue>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//* 使用数组来构造二叉树
TreeNode* buildTree(const std::vector<int>& nodes, int i = 0){
    if (i > nodes.size() || nodes[i] == INT_MIN) return nullptr;

    //* 递归构建二叉树
    TreeNode* root = new TreeNode(nodes[i]);
    root->left = buildTree(nodes, 2 * i + 1);  //* 左子树的序号为奇数
    root->right = buildTree(nodes, 2 * i + 2); //* 右子树的序号为偶数
    
    return root;
}

//* 使用数组来输出二叉树
std::vector<int> getTreeValues(TreeNode* root) {
    std::vector<int> values;
    if(root == nullptr) return values;

    std::queue<TreeNode*> que;
    que.push(root);
    while(!que.empty()){
        TreeNode* node = que.front();
        que.pop();

        if (node != nullptr){
            values.push_back(node->val);

            //* 将左右子节点加入队列
            if (node->left != nullptr || node->right != nullptr){ 
                que.push(node->left); 
                que.push(node->right);
            }
        } else {
            values.push_back(INT_MIN);
        }
    }

    return values;
}

void deleteTree(TreeNode* root){
    if (root == nullptr) return;

    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}