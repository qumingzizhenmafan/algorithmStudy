#include "../../stdc.h"


class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        sort(coins.begin(), coins.end());
        coins.push_back(target + 1);
        int result = 0;
        /*int sum = 1;
        for(int i = coins[0]; i / 2 != 0; i /= 2){
            result++;
            sum *= 2;
            cout << 0 << " " ;
        }
        if(sum != 1) sum += coins[0];*/
        int sum = 0;
        for(int i = 0; i < coins.size(); i++){
            while(coins[i] - 1 > sum) {
                result++;
                sum = sum * 2 + 1;
                cout << 1 << " " ;
            }
            if(sum < target) sum += coins[i];
            else break;
        }
        /*while(sum < target){
            result++;
            sum = sum * 2 + 1; 
            cout << 2 << " " ;
        }*/
        return result;

    }
};