#include "../../zyfziyongtou.h"

//解1和解2都是直接将前缀加入到set中，然后直接搜索，只是实现方法不一样
//相较于我的解法，多了一些搜索的操作，但减少了对数字的操作
//也许我的解法可以优化以达到更好（应该不会）
//我的解法遍历规模为n, 搜索的规模为n / 9; 
//题解遍历规模为10n, 搜索的规模只需要log(10n) 
//尤其在数据差异不大时，搜索的规模差异变得非常大

class Solution {
public:
    int longestCommonPrefix(vector<int> &arr1, vector<int> &arr2) {
        unordered_map<char,unordered_set<string>> st;
        for (int x : arr1) {
            string s = to_string(x);
            for (size_t i = 1; i <= s.length(); i++) {
                st[s[0]].insert(s.substr(0, i));
            }
        }

        int ans = 0;
        for (int x : arr2) {
            string s = to_string(x);
            for (size_t i = 1; i <= s.length(); i++) {
                //contains是c++20的用法
                //if (!st[s[0]].contains(s.substr(0, i))) {
                if(st[s[0]].find(s.substr(0, i)) == st[s[0]].end()){
                    break;
                }
                ans = max(ans, (int)i);
            }
        }
        return ans;
    }
};

/* 作者：灵茶山艾府
链接：https://leetcode.cn/problems/find-the-length-of-the-longest-common-prefix/solutions/2644176/liang-chong-xie-fa-yong-zi-fu-chuan-bu-y-qwh8/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。 */
