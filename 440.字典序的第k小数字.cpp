/*
 * @lc app=leetcode.cn id=440 lang=cpp
 *
 * [440] 字典序的第K小数字
 */

// @lc code=start
class Solution {
public:
    typedef long long ll;

    ll get_count(ll pre,ll n){
        ll cnt=0;
        for(ll a=pre,b=pre+1;a<=n;a*=10,b*=10){
            cnt += min(b,n+1)-a;
        }
        return cnt;
    }

    int findKthNumber(int n, int k) {
        ll prefix=1,p=1,cnt;
        while(p<k){
            cnt = get_count(prefix,n);
            if(p+cnt>k){
                prefix*=10;
                p++;
            }
            else if(p+cnt<=k){
                prefix++;
                p+=cnt;
            }
        }
        return prefix;
    }
};
// @lc code=end

