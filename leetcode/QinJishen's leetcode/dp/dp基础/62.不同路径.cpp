#include "../print.h"
/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

// @lc code=start
#include <vector>

class Solution {
public:
    int uniquePaths(int m, int n) {
        //* dp数组
        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

        //* dp初始化
        dp[0][0] = 1;
        dp[1][0] = 1;
        dp[0][1] = 1;

        //* dp遍历顺序
        for(int i = 2; i <= m; i++) dp[i][0] = 1;
        for(int j = 2; j <= n; j++) dp[0][j] = 1;

        for(int i = 1; i <= m - 1; i++){
            for(int j = 1; j <= n - 1; j++){
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        print(dp);
        return dp[m - 1][n - 1];
    }
};
// @lc code=end

int main(){
    Solution s;
    int res = s.uniquePaths(51, 9);
    std::cout << "res:" << res << std::endl;
    return 0;
}