/*
 * @lc app=leetcode id=32 lang=cpp
 *
 * [32] Longest Valid Parentheses
 */
class Solution {
public:
    int longestValidParentheses(string s) {
        int l,r,n,ans;
        l=r=n=ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')l++;
            else if(s[i]==')'){
                if(l>0)l--;
                else s[i]='_';
            }
        }
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]==')')r++;
            else if(s[i]=='('){
                if(r>0)r--;
                else s[i]='_';
            }
        }
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                l++;
            }
            else if(s[i]==')'){
                if(l>0){
                    l--;
                    n++;
                    ans = n>ans?n:ans;
                }
                else{
                    n=0;
                    l=0;
                }
            }
            else{
                n=0;l=0;
            }
        }
        ans*=2;
        return ans;
    }
};

