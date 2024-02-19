#include "../../../stdc.h"

using namespace std;


//可以用字符串表示一个学生的出勤记录，其中的每个字符用来标记当天的出勤情况（缺勤、迟到、到场）。记录中只含下面三种字符：
//
// 
// 'A'：Absent，缺勤 
// 'L'：Late，迟到 
// 'P'：Present，到场 
// 
//
// 如果学生能够 同时 满足下面两个条件，则可以获得出勤奖励： 
//
// 
// 按 总出勤 计，学生缺勤（'A'）严格 少于两天。 
// 学生 不会 存在 连续 3 天或 连续 3 天以上的迟到（'L'）记录。 
// 
//
// 给你一个整数 n ，表示出勤记录的长度（次数）。请你返回记录长度为 n 时，可能获得出勤奖励的记录情况 数量 。答案可能很大，所以返回对 10⁹ + 7 
//取余 的结果。 
//
// 
//
// 示例 1： 
//
// 
//输入：n = 2
//输出：8
//解释：
//有 8 种长度为 2 的记录将被视为可奖励：
//"PP" , "AP", "PA", "LP", "PL", "AL", "LA", "LL" 
//只有"AA"不会被视为可奖励，因为缺勤次数为 2 次（需要少于 2 次）。
// 
//
// 示例 2： 
//
// 
//输入：n = 1
//输出：3
// 
//
// 示例 3： 
//
// 
//输入：n = 10101
//输出：183236316
// 
//
// 
//
// 提示： 
//
// 
// 1 <= n <= 10⁵ 
// 
//
// Related Topics 动态规划 👍 307 👎 0


namespace solution552{
    //leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int checkRecord(int n) {
        for(int i=0;i<n;++i){
            temp[0]=(pre[0]+pre[1]+pre[2])%mod;
            temp[1]=pre[0]%mod;
            temp[2]=pre[1]%mod;
            temp[3]= accumulate(pre.begin(),pre.end(),(long long)0);
            temp[4]=pre[3]%mod;
            temp[5]=pre[4]%mod;
            pre = temp;
        }
        long long result = accumulate(temp.begin(),temp.end(),(long long )0)%mod;
        result %= mod;
        return (int)result;
    }
    long long acc(const vector<long long>&vec){
        long long sum = 0;
        for(auto item:vec){
            sum+=item;
        }
        return sum;
    }
private:
    int num=0;
    vector<long long >pre={1,0,0,0,0,0};
    vector<long long >temp = vector<long long>(6,0);
    int mod = 1e9+7;
};
//leetcode submit region end(Prohibit modification and deletion)

}

using namespace solution552;
int main() {
    Solution solution = Solution();
    cout << solution.checkRecord(10101);
    return 0;
}
