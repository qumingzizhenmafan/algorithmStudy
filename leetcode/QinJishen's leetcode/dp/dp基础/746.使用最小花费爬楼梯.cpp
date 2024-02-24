/*
 * @lc app=leetcode.cn id=746 lang=cpp
 *
 * [746] 使用最小花费爬楼梯
 */

// @lc code=start
#include <algorithm>
#include <vector>
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        //* dp 爬到第 i 个楼梯需要的费用
        std::vector<int> dp(cost.size() + 1, 0);
        if (cost.empty()) return 0;
        if (cost.size() == 1) return cost[0];
        dp[0] = 0;
        dp[1] = 0;

        for(int i = 2; i <= cost.size(); i++){
            dp[i] = std::min(dp[i - 2] + cost[i - 2],
                            dp[i - 1] + cost[i - 1]);
        }

        return dp[cost.size()];
    }
};
// @lc code=end

