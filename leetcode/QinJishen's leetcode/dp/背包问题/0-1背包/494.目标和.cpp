/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */

// @lc code=start
#include <algorithm>
#include <vector>
class Solution {
public:
    int findTargetSumWays(std::vector<int>& nums, int target) {
        int sum = 0;
        for(int num : nums){
            sum += num;
        }

        if ((sum + target) % 2 == 1 || abs(target) > sum) return 0;
        int bagsize = (sum + target) / 2;


        std::vector<int> dp(bagsize + 1, 0);
        
        dp[0] = 1;
        for(int i = 0; i < nums.size(); i++){
            for(int j = bagsize; j >= nums[i]; j--){
                dp[j] += dp[j - nums[i]];
            }
        }

        return dp[bagsize];
    }
};
// @lc code=end

int main(){
    Solution s;
    std::vector<int> nums = {1, 1, 1, 1, 1};
    int methods = s.findTargetSumWays(nums, 3);
    return methods;
}