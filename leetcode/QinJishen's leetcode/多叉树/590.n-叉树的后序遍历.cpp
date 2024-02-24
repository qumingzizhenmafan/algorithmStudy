/*
 * @lc app=leetcode.cn id=590 lang=cpp
 *
 * [590] N 叉树的后序遍历
 */

// @lc code=start
/*
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
*/


//* 这道题太简单了
#include <vector>
class Solution {
private:
    std::vector<int> path;

    void traversal(Node* root){
        if (root == nullptr) return;

        for(int i = 0; i < root->children.size(); i++){
            traversal(root->children[i]);
        }

        path.push_back(root->val);
        return;
    }

public:
    vector<int> postorder(Node* root) {
        if (root == nullptr) return path;
        traversal(root);
        return path;
    }
};
// @lc code=end

