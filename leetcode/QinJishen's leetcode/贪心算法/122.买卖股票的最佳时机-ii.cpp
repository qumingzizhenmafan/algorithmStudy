/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
#include <algorithm>
#include <climits>
#include <vector>
class Solution {
public:
    // 局部最优解: 
    // 全局最优解:
    int maxProfit(std::vector<int>& prices) {
        std::vector<int> profit;
        int cur_profit = 0;

        for(int i = 0; i < prices.size() - 1; i++){
            cur_profit = prices[i + 1] - prices[i];
            profit.push_back(cur_profit);
        }

        int sum = 0;

        for(int i = 0; i < profit.size(); i++){
            if (profit[i] > 0){
                sum += profit[i];
                continue;
            }
        }

        return sum;
    }
};
// @lc code=end

int main(){
    Solution s;
    std::vector<int> price = {7, 1, 5, 3, 6, 4};
    int res = s.maxProfit(price);
    return res;
}