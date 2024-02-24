/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */

//! 解数独不仅要判断位置, 还要判断内容

// @lc code=start
#include <vector>
class Solution {
private:
    bool backtracking(std::vector<std::vector<char>>& board){
        for (int row = 0; row < board.size(); row++){
            for (int col = 0; col < board[0].size(); col++){
                
                // 遇见 '.' 才处理数独内容
                if (board[row][col] == '.'){
                    
                    // 放入字符
                    for (char num = '1'; num <= '9'; num++){
                        
                        // 字符是否合法
                        if (isValid(row, col, num, board)){
                            board[row][col] = num;
                            if(backtracking(board)) return true;
                            board[row][col] = '.';
                        }
                    }

                    return false;
                }
            }
        }


        return true;
    }

    bool isValid(int row, int col, char val, vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) { // 判断行里是否重复
            if (board[row][i] == val) {
                return false;
            }
        }
        for (int j = 0; j < 9; j++) { // 判断列里是否重复
            if (board[j][col] == val) {
                return false;
            }
        }
        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;
        for (int i = startRow; i < startRow + 3; i++) { // 判断9方格里是否重复
            for (int j = startCol; j < startCol + 3; j++) {
                if (board[i][j] == val ) {
                    return false;
                }
            }
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        backtracking(board);
    }
};
// @lc code=end

