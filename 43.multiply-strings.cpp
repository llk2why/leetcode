#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=43 lang=cpp
 *
 * [43] Multiply Strings
 */

// @lc code=start
class Solution {
public:
    string multiply(string num1, string num2) {
        const int MAXN = 230;
        int a[MAXN],b[MAXN],c[MAXN],ans[MAXN];
        if(num1=="0"||num2=="0")return "0";
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(c,0,sizeof(c));
        memset(ans,0,sizeof(ans));
        int l1=num1.size(),l2=num2.size();
        for(int i=0;i<l1;i++)
            a[i]=num1[l1-i-1]-'0';
        for(int i=0;i<l2;i++)
            b[i]=num2[l2-i-1]-'0';
        string res="";
        for(int i=0;i<l1;i++){
            for(int j=0;j<l2;j++){
                int t = ans[i+j]+a[i]*b[j]+c[i+j];
                c[i+j]=0;
                ans[i+j] = t%10;
                c[i+j+1] += t/10;
            }
        }
        for(int i=0;i<l1+l2+3;i++){
            int t = ans[i]+c[i];
            ans[i] = t%10;
            c[i+1] += t/10;
        }
        bool flag=false;
        for(int i=l1+l2+2;i>=0;i--){
            if(ans[i]==0){
                if(flag)res+='0';
            }
            else{
                res+=ans[i]+'0';
                flag=true;
            }
        }
        // reverse(res.begin(),res.end());
        return res;
    }
};
// @lc code=end

int main(){
    Solution s;
    string a="9",b="9";
    cout<<s.multiply(a,b)<<endl;
}

