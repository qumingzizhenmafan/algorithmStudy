/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
#include <algorithm>
#include <vector>
class Solution {
private:
    std::vector<int> path;
    std::vector<std::vector<int>> result;
    void backtracking(std::vector<int>nums, std::vector<bool> used){
        //* 终止条件
        if (path.size() == nums.size()){
            result.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++){
            //* used[i - 1] == true，说明同一树枝nums[i - 1]使用过
            //* used[i - 1] == false，说明同一树层nums[i - 1]使用过
            //* 如果同一树层nums[i - 1]使用过则直接跳过
            if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) {
                continue;
            }
            if (used[i] == false){
                used[i] = true;
                path.push_back(nums[i]);
                backtracking(nums, used);
                path.pop_back();
                used[i] = false;
            }
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        if (nums.empty()) return result;
        std::vector<bool> used(nums.size(), false);
        std::sort(nums.begin(), nums.end());
        backtracking(nums, used);
        return result;
    }
};
// @lc code=end

