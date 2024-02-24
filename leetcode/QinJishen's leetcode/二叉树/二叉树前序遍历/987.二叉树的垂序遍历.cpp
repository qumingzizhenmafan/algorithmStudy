/*
 * @lc app=leetcode.cn id=987 lang=cpp
 *
 * [987] 二叉树的垂序遍历
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

#include <algorithm>
#include <map>
#include <utility>
#include <vector>
class Solution {
private:
    struct SameRow{
        int row;
        int value;
        SameRow(int row, int value) : row(row), value(value) { }
    };

    std::map<int, std::vector<SameRow>> path;
    std::vector<std::vector<int>> result;
    void backtracking(TreeNode* root, int row, int col){
        if (root == nullptr) return;

        //* 单层递归逻辑
        path[col].push_back(SameRow(row, root->val));
        backtracking(root->left, row + 1, col - 1);
        backtracking(root->right, row + 1, col + 1);
    }

    std::map<int, std::vector<int>> merge(std::map<int, std::vector<SameRow>> path)
    {
        std::map<int, std::vector<int>> merged;

        for (const auto& p : path){
            int col = p.first;

            const auto& rows = p.second;

            //* 先按行排序, 如果行相同则按值排序
            std::vector<SameRow> sortedRows(rows);
            std::sort(sortedRows.begin(), sortedRows.end(), 
                      [](const SameRow& a, const SameRow& b)
            {
                if (a.row == b.row) return a.value < b.value;
                return a.row < b.row;
            });
            
            //* 保留 Value, 去除 row
            std::vector<int> values;
            for (const auto& element : sortedRows){
                values.push_back(element.value);
            }
            merged[col] = values;
        }

        return merged;
    }
public:
    std::vector<std::vector<int>> verticalTraversal(TreeNode* root) {
        if (root == nullptr) return result;
        backtracking(root, 0, 0);
        std::map<int, std::vector<int>> copy = merge(path);
        for(std::map<int, std::vector<int>>::iterator 
                m = copy.begin();
                m != copy.end(); m++)
        {
            result.push_back(m->second);
        }
        return result;
    }
};



// @lc code=end
