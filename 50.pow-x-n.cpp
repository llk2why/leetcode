/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

@lc code=start
class Solution {
public:
    double myPow(double x, int n) {
        if(x==0)return 0.0;
        if(n==0)return 1.0;
        bool neg = n<0;
        int m = n>0?n:-(n+1);
        double p=x,res=1;
        while(m){
            if(m&1)res*=p;
            m>>=1;
            p=p*p;
        }
        return neg?res=1/res/x:res;
    }
};
// @lc code=end

