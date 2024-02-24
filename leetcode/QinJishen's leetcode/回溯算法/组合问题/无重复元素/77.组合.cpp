/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
#include <vector>
class Solution {
public:
    std::vector<std::vector<int>> result;
    std::vector<int> path;
    vector<vector<int>> combine(int n, int k) {
        backtracking(n, k, 1);
        return result;
    }

    void backtracking(int n, int k, int startIndex){
        //* 终止条件
        if (path.size() == k){
            result.push_back(path);
            return;
        }

        //* 单层逻辑(剪枝操作)
        for(int i = startIndex; i <= n - (k - path.size() ) + 1; i++){
            path.push_back(i);
            backtracking(n, k, i + 1);
            path.pop_back();
        }

        return;
    }
};
// @lc code=end

