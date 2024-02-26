#include "../../stdc.h"

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
private:
    int res = 0;//记录摄像头数量
    bool judge(TreeNode* root){//判断是否为极底层的叶子节点（是否满足剪枝的条件）
        if(root == nullptr || root->val == 1) return false;
        if((root->left == nullptr || (root->left->val == 1 && judge1(root->left))) && (root->right == nullptr || (root->right->val == 1 && judge1(root->right)))) return true;
        else return false;
    }
    bool judge1(TreeNode* root){
        if((root->left == nullptr || root->left->val == 1) && (root->right == nullptr || root->right->val == 1)) return true;
        else return false;
    }//判断是否为叶子节点
    void dps(TreeNode* root, int& i){//深度优先搜索
        //每次都从最底下将叶子节点剪枝（值设为1），因为题目的条件，所以每次都使用父节点作为监控以达到最大覆盖面积来计算最小监控数量以达到贪心条件
        //判断该节点的孙子节点是否是叶子节点，且该孙子节点不满足该条件，否则无法贪心的剪枝
        if((root->left != nullptr && (judge(root->left->left) || judge(root->left->right)))){
            cout << 1;
            root->val = 1;
            root->left->val = 1;
            if(root->left->left != nullptr) root->left->left->val = 1;
            if(root->left->right != nullptr) root->left->right->val = 1;
            res++;
            i = 1;
        }else if((root->right != nullptr && (judge(root->right->left) || judge(root->right->right)))){
            cout << 2;
            root->val = 1;
            root->right->val = 1;
            if(root->right->left != nullptr) root->right->left->val = 1;
            if(root->right->right != nullptr) root->right->right->val = 1;
            res++;
            i = 1;
        }else if(0){//计划对于深度为1和2的子树另外考虑，结果会导致无法满足贪心条件
            if((root->left != nullptr && judge(root->left)) || (root->right != nullptr && judge(root->right))){
                cout << 3;
                res++;
                root->val = 1;
                if(root->left != nullptr) root->left->val = 1;
                if(root->right != nullptr) root->right->val = 1;
                i = 1;
            }else if(judge(root)){
                cout << 4;
                res++;
                root->val = 1;
                i = 1;
            }
        }
        if(root->left != nullptr) dps(root->left, i);
        if(root->right != nullptr) dps(root->right, i);
    }
    int deep(TreeNode* root){//用来计算树的深度，以使用迭代dps来寻找，但弃用
        int deep = 0;
        if(root == nullptr) return deep;
        deque<TreeNode*> q;
        q.push_back(root);
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                if(q.front()->left != nullptr) q.push_back(q.front()->left);
                if(q.front()->right != nullptr) q.push_back(q.front()->right);
                q.pop_front();
            }
            deep++;
        }
        return deep;
    }
public:
    int minCameraCover(TreeNode* root) {
        int d = deep(root);
        if(d == 0) return 0;
        if(d == 1 || d == 2) return 1;
        int i = 1;   
        while(i == 1 && d >= 0){
            dps(root, i);
            d -= 3;
        }
        if(judge(root->left) || judge(root->right)){//最后判断根节点深度小于3的情况
            root->val = 1;
            res++;
            if(root->left != nullptr) root->left->val = 1;
            if(root->right != nullptr) root->right->val = 1; 
        }else if(judge(root)){
            root->val = 1;
            res++;
        }
        return res;
    }
};
int main(){
    Solution s;
    TreeNode* root = new TreeNode(0);
    //root->right = new TreeNode(0);
    root->left = new TreeNode(0);
    root->left->left = new TreeNode(0);
    //root->left->right = new TreeNode(0);
    //root->right->left = new TreeNode(0);
    //root->right->right = new TreeNode(0);
    root->left->left->left = new TreeNode(0);
    //root->left->right->right = new TreeNode(0);
    root->left->left->left->right = new TreeNode(0);
    cout << s.minCameraCover(root);
    return 0;

}