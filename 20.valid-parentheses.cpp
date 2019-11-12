/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        if(s.size()==0)return true;
        if(s.size()%2)return false;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('||s[i]=='['||s[i]=='{')st.push(s[i]);
            else{
                if(st.empty())return false;
                char ch = st.top();
                if(s[i]==')'&&ch=='(' || s[i]==']'&&ch=='[' || s[i]=='}'&&ch=='{')
                    st.pop();
                else return false;
            }
        }
        if(!st.empty())return false;
        return true;
    }
};

