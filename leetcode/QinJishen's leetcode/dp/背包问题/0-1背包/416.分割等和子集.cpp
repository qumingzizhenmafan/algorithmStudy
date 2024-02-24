#include "./dp/print.h"
/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */

// @lc code=start
#include <algorithm>
#include <vector>
class Solution {
public:
    bool canPartition(std::vector<int>& nums) {
        int sum = 0;
        for (auto num : nums){
            sum += num;
        }

        if (sum % 2 == 1) return false;
        
        int target = sum / 2;
        std::vector<int> dp(target + 1, 0);
        
        for(int i = 0; i < nums.size(); i++){
            for(int j = target; j >= nums[i]; j--){
                dp[j] = std::max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }

        return dp[target] == target;
    }
};
// @lc code=end

int main(){
    Solution s;
    std::vector<int> nums = {1, 2, 3, 5};
    bool res = s.canPartition(nums);
    return res;
}