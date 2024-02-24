#include <iostream>
#include <vector>
#include "./dp/print.h"

using namespace std;


void get_comb_(vector<int>& nums, int target){
    //* dp[i][j] 表示总金额为 j 的背包使用前 i 个 nums 有多少种组合
    std::vector<std::vector<int>> 
        ddp(nums.size() + 1, std::vector<int>(target + 1, 0));

    for(int i = 0; i <= nums.size(); i++){
        ddp[i][0] = 1;   
    }

    //* 先物品, 再背包: 横向遍历
    for(int i = 1; i <= nums.size(); i++){
        for(int j = 0; j <= target; j++){
            ddp[i][j] = ddp[i-1][j];
            if (j >= nums[i-1]) {
                ddp[i][j] += ddp[i][j - nums[i-1]];
            }
        }
    }

    print(ddp);

    std::cout << "求组合数: " << std::endl;

    //* dp[j] 表示总金额为 j 的背包有多少种组合
    std::vector<int> dp(target + 1, 0);

    dp[0] = 1;
    //* 先物品, 再背包: 横向遍历
    for(int i = 0; i < nums.size(); i++){
        for(int j = nums[i]; j <= target; j++){
            dp[j] += dp[j - nums[i]];
        }
    }

    print(dp);
}

void get_perm_(vector<int>& nums, int target){

    std::cout << "求排列数: " << std::endl;
    std::vector<int> dp(target + 1, 0);

    dp[0] = 1;
    for(int j = 1; j <= target; j++){
        for(int i = 0; i < nums.size(); i++){
            if (j >= nums[i]) 
                dp[j] += dp[j - nums[i]];
        }
    }

    print(dp);
}

int main(){
    vector<int> combination = {1, 2, 3};
    vector<int> permutation = {1, 2, 3};

    
    get_comb_(combination, 4);
    get_perm_(permutation, 4);

    return 0;
}
