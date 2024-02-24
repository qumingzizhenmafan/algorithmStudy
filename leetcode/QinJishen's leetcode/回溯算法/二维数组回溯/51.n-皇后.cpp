/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
#include <string>
#include <vector>
class Solution {
private:
    std::vector<std::vector<std::string>> result;
    void backtracking(std::vector<std::string> chessboard, int n, int row){
        //* 终止条件
        if(row == n){
            result.push_back(chessboard);
            return;
        }

        //* 单层递归逻辑
        for(int i = 0; i < n; i++){
            // 合法判断
            if(isValid(row, i, chessboard, n)){
                chessboard[row][i] = 'Q';
                backtracking(chessboard, n, row + 1);
                chessboard[row][i] = '.';
            }
        }
        
    }

    bool isValid(int row, int col, std::vector<std::string>& chessboard, int n){
        //* 检查列
        for (int i = 0; i < row; i++){
            if (chessboard[i][col] == 'Q') return false;
        }

        //* 检查 45° 是否有皇后
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j-- ){
            if (chessboard[i][j] == 'Q') return false;
        }

        //* 检查 135° 是否有皇后
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++){
            if (chessboard[i][j] == 'Q') return false;
        }
        
        return true;
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        std::vector<std::string> chessboard(n, std::string(n, '.'));
        backtracking(chessboard, n, 0);
        return result;
    }
};
// @lc code=end

