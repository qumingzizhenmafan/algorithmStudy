/*
 * @lc app=leetcode.cn id=474 lang=cpp
 *
 * [474] 一和零
 */

// @lc code=start
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {

        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

        for(auto str: strs){
            int x = 0, y = 0; //* '0' 和 '1' 的数量

            for(auto c: str){
                if(c == '0') x++;
                else y++;
            }

            for(int i = m; i >= x; i--){
                for(int j = n; j >= y; j--){
                    dp[i][j] = std::max(dp[i][j], dp[i - x][j - y] + 1);
                }
            }
        }
        
        return dp[m][n];
    }
};
// @lc code=end

