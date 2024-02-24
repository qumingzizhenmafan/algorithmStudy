/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
#include <algorithm>
#include <climits>
#include <vector>
class Solution {
public:
    //* 局部最优解: 当前跳跃的覆盖范围最大
    //* 全局最优解: 能够覆盖到数组的最后一个下标
    bool canJump(std::vector<int>& nums) {
        if (nums.size() == 1) return true;
        int max_cover = 0;

        for(int i = 0; i <= max_cover; i++){
            max_cover = std::max(max_cover, i + nums[i]);
            if (max_cover >= nums.size() - 1) return true;;
        }
        
        return false;
    }
};
// @lc code=end

