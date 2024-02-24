/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @lc code=start
#include <string>
#include <vector>
class Solution {
private:
    std::vector<std::string> path;
    std::vector<std::vector<std::string>> result;

    //* 回文判断
    bool isPalindrome(const string& s, int startIndex, int endIndex){
        while (startIndex < endIndex){
            if (s[startIndex] != s[endIndex]){
                return false;
            }
            startIndex++;
            endIndex--;
        }

        return true;
    }

    void backtracking(const string& s, int startIndex){
        //* 递归终止条件
        //* startIndex 等效一个分割符, 当最后一个元素被分割时终止
        if (startIndex == s.size()){
            result.push_back(path);
            return;
        }

        //* 单层递归逻辑
        for (int i = startIndex; i < s.size(); ++i){
            //* 子串的范围 (startIndex, i]
            if (isPalindrome(s, startIndex, i)){
                //* substr函数 切割子串
                string str = s.substr(startIndex, i - startIndex + 1);
                path.push_back(str);
                backtracking(s, i + 1);
                path.pop_back();
            }
        }

        return;
    }

public:
    vector<vector<string>> partition(string s) {
        if (s.empty()) return result;
        backtracking(s, 0);
        return result;
    }
};
// @lc code=end

