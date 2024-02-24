#include "./回溯算法/printContentOfvector.h"
using namespace std;
/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution {
private:
    std::vector<int> path;
    std::vector<std::vector<int>> result;
    void backtracking(std::vector<int>& nums, int startIndex){
        result.push_back(path);
        //* 终止条件
        if (startIndex >= nums.size()){
            return;
        }

        //* 单层递归逻辑
        for (int i = startIndex; i < nums.size(); i++){
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }

        return;
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        if (nums.empty()) return result;
        backtracking(nums, 0);
        return result;
    }
};
// @lc code=end

int main(){
    Solution s;
    std::vector<int> v = {1, 2, 3};
    std::vector<std::vector<int>> vi = s.subsets(v);

    PrintContentOfvector<std::vector<std::vector<int>>, int> p;
    p.print(vi);

    return 0;
}