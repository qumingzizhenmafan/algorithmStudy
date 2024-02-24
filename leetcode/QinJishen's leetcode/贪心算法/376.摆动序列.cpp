/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 摆动序列
 */

// @lc code=start
#include <vector>
class Solution {
public:
    //* 局部最优解: 删除坡度上的单调元素 和 处理平坡问题
    //* 全局最优解: 找到最长的摆动序列
    int wiggleMaxLength(std::vector<int>& nums) {
        
        
        int prediff = 0; 
        int curdiff = 0;
        int result = 1;     //* 默认最右边是一个波动
        
        //* 去重逻辑: [0, 0]和[0, 0, 0]
        for (int i = 0; i < nums.size(); i++){
            if (i + 1 < nums.size() && nums[i] == nums[i + 1]){
                nums.erase(nums.begin() + i);
                i--;
            }
        }

        //* 去重之后若只有一个元素则返回 1
        if (nums.size() == 1) return nums.size();


        //* 乘积判断坡度
        for (int i = 0; i < nums.size() - 1; i++){
            curdiff = nums[i + 1] - nums[i];
            if (curdiff * prediff < 0){
                result++;
            }
            prediff = curdiff;
        }

        return result + 1;

    }
};
// @lc code=end

int main(){
    Solution s;
    std::vector<int> nums = {1, 7, 4, 9, 2, 5};
    int res = s.wiggleMaxLength(nums);
    return res;
}