/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
#include <algorithm>
#include <vector>
class Solution {
private:
    std::vector<int> path;
    std::vector<std::vector<int>> result;
    void backtracking(vector<int> candidates, int target, int sum, int index){
        //* 终止条件
        if (sum == target){
            result.push_back(path);
            return;
        }

        //* 单层递归逻辑
        for(int i = index; i < candidates.size() ; i++){
            //* 对同一树层使用过的元素进行跳过
            if (i > index && candidates[i] == candidates[i - 1]){
                continue;
            }

            //* 使用回溯
            if (sum + candidates[i] <= target){
                path.push_back(candidates[i]);
                backtracking(candidates, target, sum + candidates[i], i + 1);
                path.pop_back();
            }
        }

        return;
    }

public:

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        if (candidates.empty()) return result;
        std::sort(candidates.begin(), candidates.end()); //* 排序便于判断同一树层是否使用相同元素
        backtracking(candidates, target, 0, 0);           //* 开始递归
        return result;
    }
};
// @lc code=end






#include <algorithm>
#include <vector>
class Solution {
private:
    std::vector<int> path;
    std::vector<std::vector<int>> result;
    void backtracking(vector<int> candidates, int target, int sum, int index, std::vector<bool>& used){
        //* 终止条件
        if (sum == target){
            result.push_back(path);
            return;
        }

        //* 单层递归逻辑
        for(int i = index; i < candidates.size() && sum + candidates[i] <= target; i++){
            //* used[i - 1] == true, 说明同一树枝 candidates[i - 1] 使用过
            //* used[i - 1] == false, 说明同一树层 candidates[i - 1] 使用过
            //* 对同一树层使用过的元素进行跳过
            if (i > 0 && candidates[i] == candidates[i - 1] && used[i - 1] == false) {
                continue;
            }
                path.push_back(candidates[i]);
                used[i] = true;
                backtracking(candidates, target, sum + candidates[i], i + 1, used);
                used[i] = false;
                path.pop_back();
        }

        return;
    }

public:

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        if (candidates.empty()) return result;
        std::vector<bool> used (candidates.size(), false);
        std::sort(candidates.begin(), candidates.end());
        backtracking(candidates, target, 0, 0, used);
        return result;
    }
};