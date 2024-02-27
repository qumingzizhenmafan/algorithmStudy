#include "../../stdc.h"
class Solution1 { //线性筛
public:
    int countPrimes(int n) {
        vector<int> primes;
        vector<int> isprimes(n, 1);
        for(int i = 2; i < n; ++i){
            if(isprimes[i]){
                primes.push_back(i);
            }
            for(int j = 0; j < primes.size() && i * primes[j] < n; ++j){
                isprimes[i * primes[j]] = 0;
                if(i % primes[j] == 0){
                    break;
                }
            }
        }
        return primes.size();
    }
};

class Solution2 { //埃式筛
public:
    int countPrimes(int n) {
        vector<int> isPrime(n, 1);
        int ans = 0;
        for (int i = 2; i < n; ++i) {
            if (isPrime[i]) {
                ans += 1;
                if ((long long)i * i < n) {
                    for (int j = i * i; j < n; j += i) {
                        isPrime[j] = 0;
                    }
                }
            }
        }
        return ans;
    }
};

/* 作者：力扣官方题解
链接：https://leetcode.cn/problems/count-primes/solutions/507273/ji-shu-zhi-shu-by-leetcode-solution/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。 */