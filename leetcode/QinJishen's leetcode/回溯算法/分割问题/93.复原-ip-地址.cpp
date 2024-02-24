/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 */

// @lc code=start
#include <string>
#include <vector>
class Solution {
private:
    std::vector<std::string> result;

    //* 切割是否合法
    //* 判断切割内容是否在 0~255
    bool isValid(const string& s, int start, int end){
        if (start > end) return false;
        
        if (s[start] == '0' && start != end) //* "0"字符开头的不符合
            return false;

        int num = 0;
        for (int i = start; i <= end; i++){
            if (s[i] < '0' || s[i] > '9') return false;
            num = num * 10 + (s[i] - '0');
            
            if (num > 255) return false;
        }

        return true;
    }

    void backtracking(string& s, int startIndex, int pointSum){
        //* 递归终止条件, 逗号数量(树的深度)为3
        if (pointSum == 3){
            if (isValid(s, startIndex, s.size() - 1)){ //* [startIndex, s.size() - 1)
                result.push_back(s);
            }
            return;
        }


        //* 单层递归逻辑
        for(int i = startIndex; i < s.size(); i++){
            if(isValid(s, startIndex, i)){
                s.insert(s.begin() + i + 1, '.');                 //* 插入'.'
                backtracking(s, i + 2, pointSum + 1); //* i + 2: 我们添加了'.'
                s.erase(s.begin() + i + 1);
            }
        }

        return;
    }

public:
    vector<string> restoreIpAddresses(string s) {
        if (s.empty()) return result;
        backtracking(s, 0, 0);
        return result;
    }
};
// @lc code=end

