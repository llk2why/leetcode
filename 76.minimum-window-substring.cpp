#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 */

// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        int minLen = INT_MAX,ls=s.size(),lt=t.size();
        string res;
        if(ls==0||lt==0||ls<lt)return res;
        unordered_map<char,int> mt,mr;
        for(int i=0;i<lt;i++)
            mt[t[i]]++;
        for(int p=0,q=0,cnt=0;q<ls;q++){
            char c = s[q];
            if(mt.find(c)!=mt.end()){
                mr[c]++;
                if(mr[c]<=mt[c])
                    cnt++;
            }
            if(cnt>=lt){
                while(mt.find(s[p])==mt.end()||mr[s[p]]>mt[s[p]]){
                    mr[s[p]]--;
                    p++;                    
                }
                if(q-p+1<minLen){
                    minLen = q-p+1;
                    res = s.substr(p,minLen);
                }
                mr[s[p]]--;
                p++;
                cnt--;
            }
        }
        return res;
    }
};
// @lc code=end
int main(){
    string s,t;
    s="ab";
    t="a";
    Solution ss;
    cout<<ss.minWindow(s,t)<<endl;
}
