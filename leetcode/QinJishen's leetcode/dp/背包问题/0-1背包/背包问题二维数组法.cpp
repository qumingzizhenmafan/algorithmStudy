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
    
    //* 初始化dp数组
    vector<vector<int>> dp(weight.size(), vector<int>(bagweight + 1, 0));
    for(int j = weight[0]; j <= bagweight; j++) {
        dp[0][j] = value[0];
    }
    
    //* 遍历逻辑
    for(int i = 1; i < weight.size(); i++){
        for(int j = 1; j <= bagweight; j++){
            if (j < weight[i]) dp[i][j] = dp[i - 1][j];
            else{
                dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
            }
        }
    }

    print(dp);
    std::cout << "maxValue:" << dp[weight.size() - 1][bagweight] << std::endl;
    
}

int main(){
    while(cin >> n >> bagweight){
        solve();
    }
    
    return 0;
}