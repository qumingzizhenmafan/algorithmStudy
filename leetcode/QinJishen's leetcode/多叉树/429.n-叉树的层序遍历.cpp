/*
 * @lc app=leetcode.cn id=429 lang=cpp
 *
 * [429] N 叉树的层序遍历
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

#include <queue>
#include <vector>
class Solution {
private:
    std::vector<int> level;
    std::vector<std::vector<int>> results;
    int level_size = 0;
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (root == nullptr) return {};
        std::queue<Node*> que;
        que.push(root);

        while(!que.empty()){
            level_size = que.size();
            while(level_size--){
                Node* node = que.front();
                que.pop();
                level.push_back(node->val);

                for (auto& next : node->children){
                    que.push(next);
                }
            }
            results.push_back(level);
            level.clear();
        }
        return results;
    }
};
// @lc code=end

