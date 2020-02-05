#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原IP地址
 */

// @lc code=start
class Solution {
    int sz;
    vector<string> res;
    int v;
    string tmp;
    stringstream ss;
    void dfs(string &s,int i, int d,string t){
        if(sz-i<4-d||sz-i>(4-d)*3)return;
        if(d>0)t+='.';
        if(d==3){
            if(s[i]=='0'&&sz-i>1)return;
            ss.clear();
            if(sz-i>3)return;
            ss<<s.substr(i,sz-i);
            ss>>v;
            if(v>=256)return;
            tmp = t + s.substr(i,sz-i);
            res.push_back(tmp);
        }
        else if(d<3){
            for(int k=1;i+k<sz&&k<=3&&(k==1||s[i]!='0');k++){
                ss.clear();
                ss<<s.substr(i,k);
                ss>>v;
                if(v>=256)return;
                tmp = t + s.substr(i,k);
                dfs(s,i+k,d+1,tmp);
            }
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        sz = s.size();
        dfs(s,0,0,"");
        return res;
    }
};
// @lc code=end

int main(){
    Solution s;
    vector<string> res = s.restoreIpAddresses("010010");
    for(auto &t:res){
        cout<<t<<endl;
    }
}