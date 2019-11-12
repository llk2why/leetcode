/*
 * @lc app=leetcode id=29 lang=cpp
 *
 * [29] Divide Two Integers
 */
class Solution {
public:
    int intmax = 2147483647;
    int intmin = -2147483648;
    int divide(int dividend, int divisor) {
        if(dividend==0)return 0;
        if(divisor==-1&&dividend==intmin)return intmax;
        if(divisor==1)return dividend;
        if(dividend==divisor)return 1;
        int sign;
        sign = (dividend^divisor)>>31?-1:1;
        bool flag=false;
        if(dividend==intmin){flag=true;dividend=intmax;}
        if(dividend<0)dividend = -dividend;
        if(divisor==intmin){
            if(dividend==intmin)return 1;
            else return 0;
        }
        if(divisor<0)divisor = -divisor;
        int res = 0;
        long long t;
        while(dividend>=divisor){
            int b = 0;
            bool ft=true;
            t = (long long)divisor<<(b+1);
            while(t<=dividend){
                b++;
                t = (long long)divisor<<(b+1);
            }
            if(dividend>=(divisor<<b)){
                dividend = dividend-(divisor<<b);
                res += 1<<b;
            }
            else{
                dividend-=divisor;
                res++;
            }
            if(flag){flag=false;dividend++;}
        }
        return sign==1?res:-res;
    }
};


