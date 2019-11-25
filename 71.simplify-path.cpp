#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=71 lang=cpp
 *
 * [71] Simplify Path
 */

// @lc code=start
class Solution {
public:
    string simplifyPath(string path) {
        string sub;
        path = path+'/';
        int pos = path.find("//"),npos;
        while(pos!=string::npos){
            path.replace(pos,2,"/");
            pos = path.find("//");
        }
        pos = 0;
        while(pos<path.size()-1){
            npos = path.find("/",pos+1);
            sub = path.substr(pos+1,npos-pos-1);
            if(sub==".."){
                if(pos!=0)pos = path.rfind("/",pos-1);
                path.erase(path.begin()+pos+1,path.begin()+npos+1);
            }
            else if(sub==".")path.erase(path.begin()+pos+1,path.begin()+npos+1);
            else pos = npos;
        }
        if(path.size()>1)path.erase(path.end()-1,path.end());
        return path;
    }
};
// @lc code=end

int main(){
    // string path = "/a//b////c/d//././/..";
    string path = "/..//././/..";
    Solution s;
    string res = s.simplifyPath(path);
    cout<<res<<endl;
    // string res = "1234";
    // cout<<res.substr(2,2)<<endl;
}
