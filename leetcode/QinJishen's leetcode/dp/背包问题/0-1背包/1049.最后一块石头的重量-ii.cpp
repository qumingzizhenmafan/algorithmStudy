#include "./dp/print.h"
/*
 * @lc app=leetcode.cn id=1049 lang=cpp
 *
 * [1049] 最后一块石头的重量 II
 */

// @lc code=start
#include <algorithm>
#include <numeric>
#include <vector>
class Solution {
public:
    int lastStoneWeightII(std::vector<int>& stones) {
        int sum = 0;
        for(auto stone : stones){
            sum += stone;
        }

        int target = sum / 2;
        std::vector<int> dp(target + 1, 0);

        //* 背包
        for(int i = 0; i < stones.size(); i++){
            for(int j = target; j >= stones[i]; j--){
                dp[j] = std::max(dp[j], dp[j - stones[i]] + stones[i]);
            }
        }

        return sum - dp[target] - dp[target];

    }
};
// @lc code=end

int main(){
    Solution s;
    std::vector<int> stones = {2, 7, 4, 1, 8, 1};
    int res = s.lastStoneWeightII(stones);
    return res;
}