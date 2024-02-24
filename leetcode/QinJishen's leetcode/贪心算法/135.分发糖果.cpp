/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
 */

// @lc code=start
#include <algorithm>
#include <vector>
class Solution {
public:
    int candy(std::vector<int>& ratings) {
        std::vector<int> Candy(ratings.size(), 1);
        for(int i = 1; i < ratings.size(); i++){
            //* 右边孩子比左边孩子得分高
            if(ratings[i - 1] < ratings[i]){
                Candy[i] = Candy[i - 1] + 1;
            }else {
                Candy[i] = 1;
            }
        }

        for(int i = ratings.size() - 1; i > 0; i--){
            //* 左边孩子比右边孩子得分高
            if(ratings[i] < ratings[i - 1]){
                Candy[i - 1] = std::max(Candy[i] + 1, Candy[i - 1]);
            }
        }

        int sum = 0;
        for (int& n : Candy) sum += n;

        return sum;
    }
};
// @lc code=end

int main(){
    Solution s;
    std::vector<int> num = {1, 2, 2, 5, 4, 3, 2};
    int res = s.candy(num);

    return res;
}