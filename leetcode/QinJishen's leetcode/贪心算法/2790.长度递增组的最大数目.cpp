/*
 * @lc app=leetcode.cn id=2790 lang=cpp
 *
 * [2790] 长度递增组的最大数目
 */

//* 思路: 采用贪心法


// @lc code=start
#include <algorithm>
#include <vector>
class Solution {
public:
    int maxIncreasingGroups(std::vector<int>& usageLimits) {
        const int size = usageLimits.size();
        std::vector<long long> copy(usageLimits.begin(), usageLimits.end());
        std::sort(copy.begin(), copy.end());

        int count = 1;
        for(int i = 0; i < size; i++){
            if (copy[i] >= count) copy[i] -= count++;
            if (i + 1 < size) copy[i + 1] += copy[i];
        }

        return count - 1;
    }
};
// @lc code=end


int main(){
    Solution s;
    std::vector<int> num = {2, 1 ,2};
    int res = s.maxIncreasingGroups(num);
    return res;
}
