#include "../printContentOfvector.h"
/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    std::vector<int> path;
    std::vector<std::vector<int>> result;

    void backtracking(std::vector<int>& candidates, int targetSum, int startIndex, int sum){
        if (sum == targetSum){
            result.push_back(path);
            return;
        }

        //* 单层递归逻辑
        for (int i = startIndex; i < candidates.size(); i++ ){
            if (sum + candidates[i] <= targetSum){
                path.push_back(candidates[i]);
                backtracking(candidates, targetSum, max(startIndex, i), sum + candidates[i]);
                path.pop_back();
            }
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if (candidates.empty()) return result;
        backtracking(candidates, target, 0, 0);
        return result;
    }
};
// @lc code=end

int main(){
    Solution s;
    std::vector<int> num = {2, 3, 6, 7};
    int target = 7;
    std::vector<std::vector<int>> res = s.combinationSum(num, target);
    PrintContentOfvector<vector<vector<int>>, int> p;
    p.print(res);
    p.print(num);
    std::cout << std::endl;
    
    return 0;
}