#include "../../zyfziyongtou.h"
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
    vector<int> preorder_class;
    vector<int> inorder_class;
    int sk = 0;
    int ni;
    int nj;
    TreeNode* leftup(int i, int j){
        if(i > j) return nullptr;
        int k = find(inorder_class.begin(), inorder_class.end(), preorder_class[sk++]) - inorder_class.begin();
        TreeNode* node = new TreeNode(inorder_class[k]);
        node ->left = leftup(i , k - 1);
        node -> right = leftup(k + 1 , j);
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        preorder_class = preorder;
        inorder_class = inorder;
        int i = 0, j = 0;
        ni = preorder.size(); nj = inorder.size() - 1;
        return leftup(i , nj);
    }
};
