#include<vector>
using std::vector;


// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


class Solution {
    vector<int> target;
    void dfs(Node* root){       
        if(!root->children.empty()){
            for(Node* node : root->children){
                dfs(node);
                
            }
        }
        target.push_back(root->val);
    }
public:
    vector<int> postorder(Node* root) {
        if(root == nullptr) return target;
        dfs(root);
        return target;
    }
};