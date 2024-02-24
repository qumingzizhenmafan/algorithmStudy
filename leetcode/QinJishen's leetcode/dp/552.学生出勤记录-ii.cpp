/*
 * @lc app=leetcode.cn id=552 lang=cpp
 *
 * [552] 学生出勤记录 II
 */

// @lc code=start
#include <iostream>
#include <string>
#include <vector>
class Solution {
private:
    static constexpr int mod = 1000000000 + 7;
    using dp_type = std::vector<std::vector<std::vector<int>>>;

    //* 打印 dp 数组
    void printdp(dp_type dp, int n){
        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= 1; j++){
                for(int k = 0; k <= 2; k++){
                    std::cout << "(" << i << ", " << j << ", " << k << ") : "
                        << dp[i][j][k] << std::endl;
                }
            }
        }
    }

public:
    int checkRecord(int n) {
        std::vector<std::vector<std::vector<int>>> 
            dp(n + 1, std::vector<std::vector<int>>(2, std::vector<int>(3)));

        //* 2个 'Absent'代表缺席无法获取出勤奖励, 3个连续的'Late'代表迟到无法获取出勤奖励
        dp[0][0][0] = 1;
        for(int i = 1; i <= n; i++){
            //* 考虑全部'P'通过的情况
            for(int j = 0; j <= 1; j++){
                for(int k = 0; k <= 2; k++){
                    dp[i][j][0] = (dp[i][j][0] + dp[i - 1][j][k]) % mod;
                }
            }

            //* 考虑最后以'A'结尾通过的情况
            for(int k = 0; k <= 2; k++){
                dp[i][1][0] = (dp[i][1][0] + dp[i - 1][0][k]) % mod;
            }

            //* 考虑最后以'L'结尾通过的情况
            for(int j = 0; j <= 1; j++){
                for(int k = 1; k <= 2; k++){
                    dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j][k - 1]) % mod;
                }
            }
        }

        int sum = 0;
        for(int j = 0; j <= 1; j++){
            for(int k = 0; k <= 2; k++){
                sum = (sum + dp[n][j][k]) % mod;
            }
        }

        //* print dp or not.
        // printdp(dp, n);
        return sum;
    }

};
// @lc code=end

int main(){
    Solution s;
    int target = 5;
    int res = s.checkRecord(target);
    return 0;
}