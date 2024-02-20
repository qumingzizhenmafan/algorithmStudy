#include "../../zyfziyongtou.h"

class Solution {
public:
    int longestCommonPrefix(vector<int> &arr1, vector<int> &arr2) {
        unordered_set<int> st;
        for (int x : arr1) {
            for (; x; x /= 10) {
                st.insert(x);
            }
        }

        int mx = 0;
        for (int x : arr2) {
            for (; x && st.find(x) != st.end(); x /= 10);
            mx = max(mx, x);
        }
        return mx ? to_string(mx).length() : 0;
    }
};

/* 作者：灵茶山艾府
链接：https://leetcode.cn/problems/find-the-length-of-the-longest-common-prefix/solutions/2644176/liang-chong-xie-fa-yong-zi-fu-chuan-bu-y-qwh8/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。 */