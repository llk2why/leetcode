/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        int a,b,mid;
        if(x==0||x==1)return x;
        a=0;
        b=x/2>46340?46340:x/2;
        mid = (a+b)/2;
        while(a<b){
            int p = mid*mid;
            if(p==x)return mid;
            else if(p>x)b=mid-1;
            else a=mid+1;
            mid=(a+b)/2;
        }
        while(mid*mid>x)mid--;
        return mid;
    }
};
// @lc code=end

