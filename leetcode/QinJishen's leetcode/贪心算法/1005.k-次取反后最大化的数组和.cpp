/*
 * @lc app=leetcode.cn id=1005 lang=cpp
 *
 * [1005] K 次取反后最大化的数组和
 */

// @lc code=start
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <climits>
#include <vector>
class Solution {
public:
    int largestSumAfterKNegations(std::vector<int>& nums, int k) {
        int sum = 0;

        // 按照绝对值排序
        std::sort(nums.begin(), nums.end(), [](const int& rhs, const int& lhs){
                return std::abs(rhs) > std::abs(lhs);
            }
        );

        // 从绝对值大的负数开始转变成正数
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] < 0 && k > 0){
                nums[i] *= -1;
                k--;
            }
        }

        // 绝对值最小的数来处理剩余的 k
        // 如果 k 是奇数那么取相反数, 否则为 k 本身.
        if (k % 2 == 1) nums[nums.size() - 1] *= -1;

        for (int& num : nums) sum += num;

        return sum;
    }
};
// @lc code=end

int main(){
    Solution s;
    std::vector<int> nums = {2, -3, -1, 5, -4};
    int res = s.largestSumAfterKNegations(nums, 2);
    std::cout << "res:" << res << std::endl;
    
    return 0;
}


// 循环逻辑
// int largestSumAfterKNegations(std::vector<int>& nums, int k) {
//         int sum = 0;
//         int index = 0;
//         int min_num = INT_MAX;
//         while(k--){
//             for(int i = 0; i < nums.size(); i++){
//                 min_num = std::min(min_num, nums[i]);
//                 if (nums[i] == min_num) index = i;
//             }
//             nums[index] = 0 - nums[index];
//             min_num = INT_MAX;
//         }

//         for(int& num : nums){
//             sum += num;
//         }

//         return sum;
//     }