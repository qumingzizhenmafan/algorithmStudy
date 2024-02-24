/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
#include <algorithm>
#include <climits>
#include <vector>
class Solution {
    
public:
    //* 局部最优解: 用最少的跳跃次数去增加我们的覆盖范围
    //* 全局最优解: 最小的跳跃次数到达 nums[n - 1];
    int jump(std::vector<int>& nums) {
        if (nums.size() == 1) return 0;
        int cur_cover = 0;
        int next_cover = 0;
        int count = 0;

        for (int i = 0; i < nums.size(); i++){
            //* 记录这一个覆盖范围内包括的下次最大覆盖范围
            next_cover = std::max(next_cover, nums[i] + i);

            // i 遍历到当前覆盖范围的最大值, 更新新的覆盖范围
            if (i == cur_cover){
                // 当前覆盖范围仍然没有覆盖到 nums.size - 1
                if(cur_cover != nums.size() - 1){
                    count++;                                    // 覆盖次数++
                    cur_cover = next_cover;                     // 更新最大覆盖值
                    if (cur_cover >= nums.size() - 1) break;    // 更新后的覆盖范围包括 nums.size - 1
                }
            }
        }

        return count;

    }
};
// @lc code=end

int main(){
    Solution s;
    std::vector<int> nums = {5,6,4,4,6,9,4,4,7,4,4,8,2,6,8,1,5,9,6,5,2,7,9,7,9,6,9,4,1,6,8,8,4,4,2,0,3,8,5};
    std::vector<int> test = {2, 3, 1, 1, 4};
    int res = s.jump(nums);

    return res;
}

// for (int i = 0; i < nums.size(); i++){
//             next_cover = std::max(nums[i] + i, next_cover);
//             if (i == cur_cover){
//                 if (cur_cover != nums.size() - 1){
//                     count++;
//                     cur_cover = next_cover;
//                     if (cur_cover >= nums.size() - 1) break;
//                 }
//             }
//         }