/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        if(x==0)return 0;
        int a=1,b=x,mid,res=1,d=b;
        while(a<b){
            mid = a+(b-a)/2;
            int dt = x/mid;
            if(dt==mid){
                res=mid;
                break;
            }
            else if(dt>=mid){
                if(abs(mid-dt)<d){
                    res=mid;
                    d = abs(mid-dt);
                }
                a=mid+1;
            }
            else{
                if(abs(mid-dt)<d){
                    res=dt;
                    d = abs(mid-dt);
                }
                b=mid;
            }
        }
        return res;
    }
};
// @lc code=end

