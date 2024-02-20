#include"../../zyfziyongtou.h"
//105. 从前序与中序遍历序列构造二叉树
//空间花销太大，虽然也能实现，但效率太差


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//思路：构建中先将只有左子树的一条链构建，在判断在那个点添加右子树，用构建左子树的方法递归构建右子树，最后合并成树

class Solution {
    vector<int> preorder_class;
    vector<int> inorder_class;
    int ni;
    int nj;
    TreeNode* leftup(int& i, int& j, TreeNode* node){
        if(i >= ni || j >= nj) return nullptr;
        stack<TreeNode*> stkl;
        while(i < ni && preorder_class[i] != inorder_class[j]){//构建左子树链
            TreeNode* temp = new TreeNode(preorder_class[i]);
            if(!stkl.empty()) stkl.top()->left = temp;
            stkl.push(temp);
            ++i;
        }
        TreeNode* temp = new TreeNode(preorder_class[i]);
        if(!stkl.empty()) stkl.top()->left = temp;
        stkl.push(temp);
        ++i;
        do{//寻找是否有节点有右子树
            temp = stkl.top();
            stkl.pop();
            ++j;
            if(!stkl.empty() && stkl.top()->val != inorder_class[j]) temp->right = leftup(i , j, stkl.top());
        }while(!stkl.empty());
        if(node == nullptr || (node != nullptr && node->val != inorder_class[j])){//在左子树链的顶部需要额外判断右子树
            temp->right = leftup(i , j, nullptr);
            /* if(i < ni && preorder_class[i] != inorder_class[j]) temp->right = leftup(i , j, nullptr);
            else if(i < ni && preorder_class[i] == inorder_class[j]) temp->right = new TreeNode(preorder_class[i]); */
        }
        return temp;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        preorder_class = preorder;
        inorder_class = inorder;
        int i = 0, j = 0;
        ni = preorder.size(); nj = inorder.size();
        return leftup(i , j , nullptr);
    }
};

void Treeprint(TreeNode* root){
    if(root == nullptr) return;
    cout << root->val << ' ';
    Treeprint(root->left);
    Treeprint(root->right);
}
void Treeprint2(TreeNode* root){
    if(root == nullptr) return;
    Treeprint2(root->left);
    cout << root->val << ' ';
    Treeprint2(root->right);
}


int main(){
    //vector<int> preorder = {1,2,3};vector<int> inorder = {2,1,3};
    //vector<int> preorder = {-1};vector<int> inorder = {-1};
    //vector<int> preorder = {3,9,20,15,7};vector<int> inorder = {9,3,15,20,7};
    //vector<int> preorder = {3,1,2,4};vector<int> inorder = {1,2,3,4};
    //vector<int> preorder = {1,2,3};vector<int> inorder = {1,2,3};
    vector<int> preorder = {7,-10,-4,3,-1,2,-8,11};vector<int> inorder = {-10,-4,3,-1,2,-8,11,7};
    Solution s;
    TreeNode* root = s.buildTree(preorder, inorder);
    Treeprint(root);
    cout << endl;
    Treeprint2(root);
    return 0;
}