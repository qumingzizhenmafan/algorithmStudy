/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
#include <map>
#include <string>
#include <utility>
#include <vector>
class Solution {
public:
    std::map<int, std::string> m;

    Solution(){
        m.insert(std::make_pair(2, "abc"));
        m.insert(std::make_pair(3, "def"));
        m.insert(std::make_pair(4, "ghi"));
        m.insert(std::make_pair(5, "jkl"));
        m.insert(std::make_pair(6, "mno"));
        m.insert(std::make_pair(7, "pqrs"));
        m.insert(std::make_pair(8, "tuv"));
        m.insert(std::make_pair(9, "wxyz"));
    }
    
    std::string s;
    std::vector<std::string> result;
    std::vector<std::string> letterCombinations(std::string digits) {
        if (digits.empty()) return result;
        backtracking(digits, 0);
        return result;
    }

    void backtracking(std::string digits,int index){
        //* 终止条件
        if (index == digits.size()){
            result.push_back(s);
            return;
        }

        //* 单层递归逻辑
        int digit = digits[index] - '0';           //* 获取当前数字
        std::string letter = m[digit];             //* 通过 HashMap 映射获取数字对应的字符串
        for(int i = 0; i < letter.size(); i++){
            s.push_back(letter[i]);
            backtracking(digits, index + 1); //* index 表示本层递归时传入的 digits 的下标
            s.pop_back();
        }
    }
};
// @lc code=end

