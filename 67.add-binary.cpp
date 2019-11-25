#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 */

// @lc code=start
class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        int c = 0,la=a.size(),lb=b.size();
        for(int i=0;i<la||i<lb;i++){
            if(i>=la){
                if(c>0){
                    if(b[i]=='1')res+='0';
                    else{res+='1';c=0;}
                }
                else res+=b[i];
            }
            else if(i>=lb){
                if(c>0){
                    if(a[i]=='1')res+='0';
                    else{res+='1';c=0;}
                }
                else res+=a[i];
            }
            else if(c>0){
                if(a[i]=='1'&&b[i]=='1'){
                    res+='1';
                }
                else if(a[i]=='1'||b[i]=='1'){
                    res+='0';
                }
                else{
                    res+='1';
                    c=0;
                }
            }
            else{
                if(a[i]=='1'&&b[i]=='1'){
                    res+='0';
                    c=1;
                }
                else{
                    res+=(a[i]=='1'||b[i]=='1')?'1':'0';
                    c=0;
                }
            }
        }
        if(c)res+='1';
        reverse(res.begin(),res.end());
        return res;
    }
};
// @lc code=end

int main(){
    string a="11101",b="1";
    Solution s;
    cout<<s.addBinary(a,b)<<endl;
}

