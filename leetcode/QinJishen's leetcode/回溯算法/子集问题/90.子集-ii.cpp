/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

// @lc code=start
#include <algorithm>
#include <vector>
class Solution {
private:
    std::vector<int> path;
    std::vector<std::vector<int>> result;
    void backtracking(std::vector<int>& nums, int startIndex){
        result.push_back(path);
        

        //* 单层递归逻辑
        for (int i = startIndex; i < nums.size(); i++){
            //* i > startIndex 树层去重
            //* 去重前需要对数组进行排序
            if (i > startIndex  && nums[i] == nums[i - 1]){
                continue;
            }
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }

        return;
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        if (nums.empty()) return result;
        std::sort(nums.begin(), nums.end());
        backtracking(nums, 0);
        return result;
    }
};
// @lc code=end

