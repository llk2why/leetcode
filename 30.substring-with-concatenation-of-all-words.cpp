/*
 * @lc app=leetcode id=30 lang=cpp
 *
 * [30] Substring with Concatenation of All Words
 */
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        map<string,int> mp,tmp;
        vector<int> ret;
        ret.clear();
        int wl=words.size(),sl=s.size();
        if(sl<1 || wl<1)return ret;
        int l = words[0].size();
        if(wl*l>sl)return ret;
        for(int i=0;i<wl;i++)mp[words[i]]++;
        for(int i=0;i<sl-wl*l+1;i++){
            int j=0;
            tmp.clear();
            while(j<wl){
                // string str = string(s.begin()+i+j*l,s.begin()+i+(j+1)*l);
                string str = s.substr(i+j*l,l);
                tmp[str]++;
                if(tmp[str]>mp[str])break;
                j++;
                if(j>=wl){
                    ret.push_back(i);
                    break;
                }
            }
        }
        return ret;
    }
};