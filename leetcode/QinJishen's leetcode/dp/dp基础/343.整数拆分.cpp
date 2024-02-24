/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 */
#include "./dp/print.h"
// @lc code=start
#include <algorithm>
#include <vector>
class Solution {
public:
    
    int integerBreak(int n) {
        //* 对 i 进行拆解, 得到的最大积为 dp[i]
        std::vector<int> dp(n + 1, 0);
        
        dp[2] = 1;
        for(int i = 3; i <= n; i++){
            for(int j = 1; j <= i / 2; j++){
                dp[i] = std::max(
                    std::max(j * (i - j), j * dp[i - j]), dp[i]);
            }
        }
        print(dp);
        return dp[n];
    }
};

// @lc code=end


int main(){
    Solution s;
    int res = s.integerBreak(10);
    return res;
}