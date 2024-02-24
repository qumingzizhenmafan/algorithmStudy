#include <algorithm>
#include<iostream>
#include<vector>
#include "C:\Users\12194\.leetcode\dp\print.h"
using namespace std;

int n, bagweight; //* 物品数量 n 和 背包容量 bagweight

void solve(){
    std::vector<int> weight(n, 0); //* 物品重量
    std::vector<int> value(n, 0);  //* 物品价值
    for(int i = 0; i < n; ++i) {
        cin >> weight[i];
    }
    for(int j = 0; j < n; ++j) {
        cin >> value[j];
    }
    
    // 初始化dp数组
    vector<int> dp(bagweight + 1, 0);

    // 遍历逻辑
    for(int i = 0; i < weight.size(); i++){
        for(int j = bagweight; j >= weight[i]; j--){
            dp[j] = std::max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }


    print(dp);
    std::cout << "maxValue:" << dp[bagweight] << std::endl;
    
}

int main(){
    while(cin >> n >> bagweight){
        solve();
    }
    
    return 0;
}