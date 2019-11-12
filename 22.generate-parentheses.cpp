/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */
class Solution {
public:
    typedef struct{
        string str;
        int a,b;
    }N;
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        queue<N> q;
        q.push({"",0,0});
        if(n==0)return ret;
        while(!q.empty()){
            N cur = q.front();
            string str;
            int a,b;
            str=cur.str;
            a=cur.a;b=cur.b;
            q.pop();
            if(str.size()==2*n-1){
                ret.push_back(str+')');
            }
            else if (a>b)
            {
                if(a<n){
                    N p;
                    p.str=str+'(';
                    p.a=a+1;
                    p.b=b;
                    q.push(p);
                }
                N pp;
                pp.str=str+')';
                pp.a=a;
                pp.b=b+1;
                q.push(pp);
            }
            else{
                N p;
                p.str=str+'(';
                p.a=a+1;
                p.b=b;
                q.push(p);
            }
        }
        
        return ret;
    }
};