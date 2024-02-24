#include <algorithm>
#include<iostream>
#include<vector>
#include "C:\Users\12194\.leetcode\dp\print.h"
using namespace std;

int n = 3, bagweight = 4; //* 物品数量 n 和 背包容量 bagweight
std::vector<int> weight = {1, 3, 4}; //* 物品重量
std::vector<int> value = {15, 20, 30};  //* 物品价值

//* 先遍历物品, 再遍历背包
void item_knapsack_solve(){
    // 初始化dp数组
    vector<int> dp(bagweight + 1, 0);

    // 遍历逻辑
    for(int i = 0; i < weight.size(); i++){
        for(int j = weight[i]; j <= bagweight; j++){
            dp[j] = std::max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }

    print(dp);
}

//* 先遍历背包, 再遍历物品
void knapsack_item_solve(){
    // 初始化dp数组
    vector<int> dp(bagweight + 1, 0);

    // 遍历逻辑
    for(int j = 0; j <= bagweight; j++){
        for(int i = 0; i < weight.size(); i++){
            if (j - weight[i] >= 0)
                dp[j] = std::max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }

    print(dp);
}

//* 二维数组遍历过程
void solve_process(){
    vector<vector<int>> 
        dp(n + 1, vector<int>(bagweight + 1, 0));
    
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= bagweight; j++){
            dp[i][j] = dp[i - 1][j];
            if (j >= weight[i - 1]){
                dp[i][j] = dp[i][j - weight[i - 1]] + value[i - 1];
            }
        }
    }

    print(dp);
}

//* 二维数组的遍历结果
void solve_result(){
    vector<vector<int>> 
        dp(n + 1, vector<int>(bagweight + 1, 0));
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= bagweight; j++){
            if (j < weight[i - 1]) dp[i][j] = dp[i - 1][j];
            else{
                dp[i][j] = max(dp[i][j], dp[i][j - weight[i - 1]] + value[i - 1]);
            }
        }
    }

    print(dp);
}

int main(){
    int choice;
    
    std::cout << "1: 一维滚动数组 先物品 再背包" << std::endl;
    std::cout << "2: 一维滚动数组 先背包 再物品" << std::endl;
    std::cout << "3: 二维数组构建过程: " << std::endl;
    std::cin >> choice;
    switch (choice) {
        case 1: {
            item_knapsack_solve();
            break;
        }
        case 2: {
            knapsack_item_solve();
            break;
        }
        default:
            solve_process();
            std::cout << "dp: " << std::endl;
            solve_result();
            break;
    }
    
    return 0;
}