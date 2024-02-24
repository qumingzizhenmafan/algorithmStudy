/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
#include <algorithm>
#include <climits>
#include <vector>
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        std::vector<int> dp(amount + 1, amount + 1);

        dp[0] = 0;
        for(int i = 0; i < coins.size(); i++){
            for(int j = coins[i]; j <= amount; j++){
                dp[j] = std::min(dp[j - coins[i]] + 1, dp[j]);
            }
        }

        return dp[amount] > amount ? -1 : dp[amount];
    }
};
// @lc code=end

//* dp: 凑成总金额 j 所需要的最少的硬币个数是 dp[j]
//* 递推式: dp[j] = std::min(dp[j - coins[i]] + 1, dp[j]);