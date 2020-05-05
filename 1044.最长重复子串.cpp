#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=1044 lang=cpp
 *
 * [1044] 最长重复子串
 */

// @lc code=start

typedef long long ll;
class Solution {
    ll mod = 1LL<<32;
    bool check(const string &s,int l,string &res){
        int n=s.size();
        // unordered_set<ll> st;
        unordered_set<unsigned int> st;
        ll hash=0,base=1;
        for(int i=l-1;i>=0;i--){
            hash = (hash+(s[i]-'a')*base)%mod;
            base = (base*26)%mod;
        }
        st.insert((unsigned int)hash);
        for(int i=1;i+l<=n;i++){
            hash = (hash*26 - base*(s[i-1]-'a')%mod+mod)%mod;
            hash = (hash+(s[i+l-1]-'a'))%mod;
            if(st.find((unsigned int)hash)!=st.end()){res=s.substr(i,l);return true;}
            else st.insert((unsigned int)hash);
        }
        return false;
    }
public:
    string longestDupSubstring(string S) {
        int n=S.size();
        int a=1,b=n,mid;
        string res="";
        while(a<b){
            mid=(a+b)/2;
            if(check(S,mid,res))a=mid+1;
            else b=mid;
        }
        return res;
    }
};
// @lc code=end

int main(){
    Solution s;
    string str;
    cout<<s.longestDupSubstring("banana")<<endl;;
}
