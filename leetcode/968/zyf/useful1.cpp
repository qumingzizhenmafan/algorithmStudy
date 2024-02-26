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



struct Status {
    int a, b, c;
    //a:根节点加监控的情况
    //b:题目所要求的情况（全部被覆盖）
    //c:两颗子树保证自己覆盖
    //根据子树的情况即可选择最优的情况构建新的子树
    //在计算过程中需要维护最小的值 且有a >= b >= c
};

class Solution {
public:
    Status dfs(TreeNode* root) {
        if (!root) {
            return {INT_MAX / 2, 0, 0};
        }
        auto [la, lb, lc] = dfs(root->left);
        auto [ra, rb, rc] = dfs(root->right);

        int a = lc + rc + 1;
        int b = min(a, min(la + rb, ra + lb));//选择在那个位置添加监视
        int c = min(a, lb + rb);//选择由根节点来维护子树的根节点，还是各自维护自己的根节点

        return {a, b, c};
    }

    int minCameraCover(TreeNode* root) {
        auto [a, b, c] = dfs(root);
        return b;
    }
};

/* 作者：力扣官方题解
链接：https://leetcode.cn/problems/binary-tree-cameras/solutions/422860/jian-kong-er-cha-shu-by-leetcode-solution/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。 */