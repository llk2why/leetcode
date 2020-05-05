#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int mm,nn;
    unordered_map<int,unordered_map<int,int>> mp;
    int dfs(int st, int prev,int d){
        int res = 0;
        if(d==nn)return 1;
        if(d>=mm)res+=1;
        for(int i=1;i<=9;i++){
            int op = 1<<i;
            if(!(op&st))if(mp[prev].find(i)==mp[prev].end()||st&(1<<mp[prev][i])){
                    res += dfs(st|op,i,d+1);
            }
        }
        return res;
    }
public:
    int numberOfPatterns(int m, int n) {
        int res = 0;
        mm = m;
        nn = n;
        mp = {
            {1,{{3,2},{7,4},{9,5}}},
            {2,{{8,5}}},
            {3,{{1,2},{7,5},{9,6}}},
            {4,{{6,5}}},
            {5,{}},
            {6,{{4,5}}},
            {7,{{1,4},{3,5},{9,8}}},
            {8,{{2,5}}},
            {9,{{3,6},{1,5},{7,8}}},
        };
        res += 4*dfs(1<<1,1,1);
        res += 4*dfs(1<<2,2,1);
        res += dfs(1<<5,5,1);
        return res;
    }
};

int main(){
    Solution s;
    int res = s.numberOfPatterns(2,2);
    cout<<res<<endl;
}