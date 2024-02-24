/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */

// @lc code=start
#include <vector>
class Solution {
public:
    std::vector<int> path;
    std::vector<std::vector<int>> result;
    vector<vector<int>> combinationSum3(int k, int n) {
        backtracking(k, n, 1, 0);
        return result;
    }

    void backtracking(int k, int n, int startIndex, int sum){
        //* 终止条件
        if (path.size() == k) {
            if (sum == n) result.push_back(path);
            return;
        }

        //* 单层递归逻辑和剪枝策略
        for (int i = startIndex; i <= 9 - (k - path.size()) + 1; i++){
            if (sum + i <= n){
                path.push_back(i);
                backtracking(k, n, i + 1, sum + i);
                path.pop_back();
            }
        }

        return;
    }

};
// @lc code=end

