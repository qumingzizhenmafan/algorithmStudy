/*
 * @lc app=leetcode.cn id=455 lang=cpp
 *
 * [455] 分发饼干
 */

// @lc code=start
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {

        //* 使用大饼干去满足胃口大的孩子
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());

        int count = 0;            // 满足小孩数量
        int index = s.size() - 1; // 剩余饼干数量


        for(int i = g.size() - 1; i >= 0; i--){
            // 满足小孩逻辑
            if (index >= 0 && s[index] >= g[i]){
                count++;
                index--;
            }
        }

        return count;
    }
};
// @lc code=end

int main(){
    Solution s;
    std::vector<int> children = {1, 3, 7, 10};
    std::vector<int> cookies = {1, 3, 5 , 9};
    int res = s.findContentChildren(children, cookies);

    return res;
}