#include "../../stdc.h"

class Solution {
    vector<int> zhisu;
    vector<int> isprimes;
    vector<vector<int>> g;
    void zhisushuai(int n){
        zhisu[1] = 0;
        zhisu[0] = 0;
        for(int i = 2; i <= n; i++){
            if(zhisu[i]){
                isprimes.push_back(i);
            }
            for(int j = 0; j < (int)isprimes.size() && i * isprimes[j] <= n; j++){
                zhisu[i * isprimes[j]] = 0;
                if(i % isprimes[j] == 0) break;
            }
        }
    }
    int dfs(int out, int in, vector<int>& seen){
        if(g[in].size() == 0) return 0;
        // 叶子节点
        int ans = 0;
        for(int i : g[in]){
            if(i != out && zhisu[i] == 0){ ans += 1 + dfs(in, i, seen); seen.push_back(i); }
        }
        return ans;
    }
public:
    long long countPaths(int n, vector<vector<int>>& edges) {
        g.resize(n + 1);
        zhisu.resize(n + 1, 1);
        zhisushuai(n);
        for(auto& e : edges){
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }
        long long ans = 0;
        vector<int> count(n + 1, 0);
        for(int i : isprimes){//对于每个质数的遍历
            long long num1 = 0;
            long long num2 = 0;
            vector<int> seen;
            for(int j : g[i]){//对于每个质数下每个分支的统计
                long long res = 0;
                if(zhisu[j] == 1) continue;//跳过质数
                else if(count[j] != 0) res = count[j];//如果已经统计过，直接跳过
                else res = 1 + dfs(i, j, seen);
                seen.push_back(j);
                for(auto & k : seen){
                    count[k] = res;
                }
                num1 += res;
                num2 += res * res;
                seen.clear();
            }
            num1 = num1 + (num1 * num1 - num2) / 2;
            ans += num1;
        }
        return ans;
    }
};

int main(){
    //[1,2],[1,3],[2,4],[3,5],[3,6]
    vector<vector<int>> edges = {{1,2},{1,3},{2,4},{3,5},{3,6}};
    Solution s;
    cout << s.countPaths(6, edges) << endl; //1
}