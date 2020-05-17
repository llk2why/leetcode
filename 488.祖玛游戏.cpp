#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=488 lang=cpp
 *
 * [488] 祖玛游戏
 */

// @lc code=start
class Solution {
    int dfs(string bo,unordered_map<char,int>& mp){
        // cout<<bo<<endl;
        if(bo=="")return 0;
        int i=0;
        int res=-1;
        while(i<bo.size()){
            int j=i+1,need;
            while(j<bo.size()&&bo[i]==bo[j])j++;
            need = 3-(j-i);
            if(mp[bo[i]]>=need){
                need = max(0,need);
                mp[bo[i]]-=need;
                string sub = bo;
                sub.erase(i,j-i);
                int tmp = dfs(sub,mp);
                if(tmp>=0)res=res>0?min(res,tmp+need):tmp+need;
                mp[bo[i]]+=need;
            }
            i = j;
        }
        return res;
    }

public:
    int findMinStep(string board, string hand) {
        unordered_map<char,int> mp;
        for(auto e:hand)mp[e]++;
        return dfs(board,mp);
    }
};
// @lc code=end

int main(){
    Solution s;
    cout<<s.findMinStep("RBYYBBRRB","YRBGB")<<endl;
}