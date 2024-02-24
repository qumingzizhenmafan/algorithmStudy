/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
#include <algorithm>
#include <climits>
class Solution {
public:
    // 局部最优解: 求解连续和为负数时, 抛弃它且选择下一个数作为新的连续和
    // 全局最优解: 找到最大子数和
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int max_sum = INT_MIN;

        for(int i = 0; i < nums.size(); i++){
            if (sum < 0) {
                sum = nums[i];
                max_sum = std::max(sum, max_sum);
                continue;
            }
            sum += nums[i];
            max_sum = std::max(sum, max_sum);
        }

        return max_sum;
    }
};
// @lc code=end

