/*
 * @lc app=leetcode.cn id=860 lang=cpp
 *
 * [860] 柠檬水找零
 */

// @lc code=start
#include <map>
#include <vector>
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        if(bills[0] > 5) return false;

        std::map<int, int> myMap;
        myMap[5] = 0;
        myMap[10] = 0;

        for(int i = 0; i < bills.size(); i++){
            if (bills[i] == 5) myMap[bills[i]]++;
            else if (bills[i] == 10){
                if (myMap[5] == 0) return false;
                myMap[5]--;
                myMap[10]++;
            }
            else{
                //* 没有5元零钱时
                if (myMap[5] == 0) return false;

                //* 有10元零钱优先使用10元零钱
                if (myMap[10] > 0){
                    myMap[10]--;
                    myMap[5]--;
                }else{
                    myMap[5] -= 3;
                }
            }
            if (myMap[5] < 0 || myMap[10] < 0) return false;
        }

        return true;
    }
};
// @lc code=end

