/*
 * @lc app=leetcode.cn id=491 lang=cpp
 *
 * [491] 非递减子序列
 */

// @lc code=start
#include <unordered_set>
#include <vector>
class Solution {
private:
    std::vector<int> path;
    std::vector<std::vector<int>> result;
    void backtracking(std::vector<int>& nums, int startIndex){
        if (path.size() > 1){
            result.push_back(path);
        }

        //* 单层递归逻辑
        std::unordered_set<int> uset; //* 收集同一树层已经使用过的元素
        for (int i = startIndex; i < nums.size(); i++){
            //* 剪枝去重逻辑
            //* 当前值小于树枝路径存储的最小值
            //* 当前值已经存在于 uset 集合内(本树层已被使用过)
            if (!path.empty() && nums[i] < path.back()
                || uset.find(nums[i]) != uset.end()){
                continue;
            }
            
                uset.insert(nums[i]);
                path.push_back(nums[i]);
                backtracking(nums, i + 1);
                path.pop_back();
        }

    }

public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        if (nums.empty()) return result;
        backtracking(nums, 0);
        return result;
    }
};
// @lc code=end

