/*
 * @lc app=leetcode.cn id=134 lang=cpp
 *
 * [134] 加油站
 */

// @lc code=start
#include <vector>
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int cur_dif = 0;
        int total_dif = 0;
        int start = 0;

        for(int i = 0; i < gas.size(); i++){
            cur_dif += gas[i] - cost[i];    // 统计起始位置到当前为止消耗的净油量
            total_dif += gas[i] - cost[i];  // 统计消耗的净油总量
            if (cur_dif < 0){
                start = i + 1;              // 记录再出发位置
                cur_dif = 0;
            }
        }

        if(total_dif < 0) return -1;

        return start;
    }
};
// @lc code=end

