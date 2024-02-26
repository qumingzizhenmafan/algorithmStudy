#include "../../stdc.h"

class Solution {
    int isPrefixAndSuffix(string a, string b){
        size_t na = a.size();
        size_t nb = b.size();
        if(na > nb) return 0;
        if(a == b.substr(0,na) && a == b.substr(nb - na, na)) return 1;
        else return 0;
    }
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        unordered_map<char, vector<string>> dp;
        for(string s : words){
            dp[s[0]].push_back(s);
        }
        int target = 0;
        for(auto& [c,v] : dp){
            size_t n = v.size();
            for(int i = 0; i < n - 1; ++i)
                for(int j = i + 1; j < n; ++j){
                    target += isPrefixAndSuffix(v[i] , v[j]);
                }
        }
        return target;
    }
};