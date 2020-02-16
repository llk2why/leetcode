/*
 * @lc app=leetcode.cn id=668 lang=cpp
 *
 * [668] 乘法表中第k小的数
 */

// @lc code=start
class Solution {
    int lex(int m,int n,int x){
        int cnt =0;
        for(int i=1;i<=m;i++)
            cnt+=min(n,x/i);
        return cnt;
    }
public:
    int findKthNumber(int m, int n, int k) {
        int l=1,r=m*n+1,x;
        while(l<r){
            x = l + (r-l)/2;
            if(lex(m,n,x)>=k)r=x;
            else l=x+1;
        }
        return l;
    }
};
// @lc code=end

