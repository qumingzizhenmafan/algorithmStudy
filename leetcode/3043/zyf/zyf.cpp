#include "../../zyfziyongtou.h"
//将数字反转在计算后缀0的个数
//时间用时太大，尤其在处理规模大，且数据相似的用例时尤为明显，没法有效解决问题

class Solution {
    size_t target = 0;
    size_t n = 0;
    string s;
    string num_str;
    unordered_map<char, vector<pair<size_t, int>>> dp;
public:
    void re(int i){
        num_str = to_string(i);
        size_t j = num_str.size();
        reverse(num_str.begin(), num_str.end());
        i = stoi(num_str);
        dp[num_str.back()].push_back(make_pair(j , i));
    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        for(auto i : arr1) re(i);
        for(int i : arr2){
            num_str = to_string(i);
            if(num_str.size() <= target) continue;
            reverse(num_str.begin(), num_str.end());
            //cout << "daozhe";
            for(auto& [j,k] : dp[num_str.back()]){
                //cout << num_str.back();
                if((stoi(num_str) - k) % (int)pow(10, target) != 0) continue;
                if(stoi(num_str) - k == 0) {
                    //cout << "111";
                    n = num_str.size() < j ? num_str.size() : j;
                    target = target > n ? target : n;
                }else{
                    s = to_string(stoi(num_str) - k);
                    n =(find_if(s.rbegin(), s.rend(), [](const char a){
                        return a != '0';
                    }) - s.rbegin());
                    //cout << n;
                    target = target > n ? target : n;
                }
            }
        }
        return target;
    }
};


int main(){
    Solution s;
    vector<int> arr1 = {2,4,6,8,10};
    vector<int> arr2 = {102,104,106,108,110};
    cout << s.longestCommonPrefix(arr1, arr2);
    return 0;
}