#include<vector>
#include<algorithm>
#include"../../../Ourlib/printContentOfvector.h"
#include"../../../Ourlib/print.h"

class Solution {
public:
    int checkRecord(int n) {
        if(n == 1) return 3;
        long long mo = 1000000007,
            a = 2, h = 1, e = 1,
            d = 0,
            c = 2, b = 1, f = 1, g = 0,
            target = 8;
        std::vector<long long> nums(8, 0);
        for(int i = 3; i <= n; ++i){
            target = (target * 2 + mo - d + a + h) % mo;
            nums[0] = (a + h + e) % mo;
            nums[1] = (b + g + f + d + c) % mo;
            nums[2] = (a + e + h) % mo;
            nums[3] = (g + f) % mo;
            nums[4] = h;
            nums[5] = c;
            nums[6] = b;
            nums[7] = a;
            a = nums[0];
            b = nums[1];
            c = nums[2];
            d = nums[3];
            e = nums[4];
            f = nums[5];
            g = nums[6];
            h = nums[7];
        }
        return target;
    }
};

