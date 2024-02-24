/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
#include <vector>
class Solution {
private:
    std::vector<int> path;
    std::vector<std::vector<int>> result;
    void backtracking(std::vector<int>& nums, std::vector<bool> used){
        //* 终止条件
        if (path.size() == nums.size()){
            result.push_back(path);
            return;
        }

        //* 单层递归逻辑
        for (int i = 0; i < nums.size(); i++){
            if (used[i] == true) continue;

            used[i] = true;
            path.push_back(nums[i]);
            backtracking(nums, used);
            path.pop_back();
            used[i] = false;
        }

        return;
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.empty()) return result;
        //* used 记录当前树层遍历情况
        std::vector<bool> used(nums.size(), false);
        backtracking(nums, used);
        return result;
    }
};
// @lc code=end

