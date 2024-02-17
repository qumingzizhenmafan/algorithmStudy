#include <climits>
#include <vector>

#include "../../Ourlib/qjsLib/printContentOfvector.h"
using namespace std;

class Solution{
private:
    vector<int> path;
    vector<vector<int>> results;
    int minSize = INT_MAX;

    //* 深度限制搜索: Deep Limits-Search
    void DLS(int target, int maxDepth, int depth){ 
        //* 终止条件: 遍历到 maxDepth 时
        if (depth == maxDepth){
            if (path.back() == target){
                if (depth < minSize){
                    minSize = depth;
                    results.clear();                       //* 清空结果
                }
                if (depth == minSize){
                    results.push_back(path);           //* 添加当前路径
                }
            }
            return;
        }
        
        //* 单层递归逻辑
        int last = path.back();
        for(int i = 0; i < path.size(); i++){
            for(int j = i; j < path.size(); j++){
                int sum = path[i] + path[j];                //* dp
                if(sum > last && sum <= target){
                    path.push_back(sum);
                    DLS(target, maxDepth, depth + 1);
                    path.pop_back();
                }
            }
        }
        return;
    }

    //* 迭代加深过程
    void IDDFS(int target, int maxDepth){ 
        //* 最后一个元素 一定为 n, 故从 depth = 1 开始
        for(int depth = 1; depth < maxDepth; depth++){
            DLS(target, depth, 1);
        }
    }

public:

    vector<vector<int>> getAdditionChain(int n){
        if (n <= 1) return {{n}};
        path.push_back(1);
        IDDFS(n, n);
        return results;
    }
};

int main(){
    int target = 5;
    Solution s;
    PrintContentOfvector<vector<vector<int>>, int> p;

    vector<vector<int>> ans = s.getAdditionChain(target);
    
    p.print(ans);
    return 0;
}