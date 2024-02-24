#include "../dpTp.h"
#include "../print.h"
#include <iostream>
#include <vector>
/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */

// @lc code=start
#include <vector>
class Solution {
private:
    std::vector<std::vector<int>> dp;
public:
    std::vector<std::vector<int>> copy(){
        std::vector<std::vector<int>> res(dp);
        return res;
    }

    int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        //* 如果障碍物在起点或者在终点:
        if (obstacleGrid[m - 1][n - 1] || obstacleGrid[0][0] == 1) return 0;

        //* 确定dp数组大小
        dp.resize(m);
        for(int i = 0; i < m; i++){
            dp[i].resize(n);
        }
        
        //* 初始化dp数组
        dp[0][0] = 1;
        for(int i = 1; i < m && obstacleGrid[i][0] != 1; i++){
            dp[i][0] = 1;
        }
        for(int j = 1; j < n && obstacleGrid[0][j] != 1; j++){
            dp[0][j] = 1;
        }

        //* dp遍历顺序
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                if(obstacleGrid[i][j] == 1) continue;
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[m - 1][n - 1];
    }
};
// @lc code=end

int main(){
    Solution s;
    v2v_int_type Grid = {{1}};
    s.uniquePathsWithObstacles(Grid);
    print(s.copy());
    return 0;
}