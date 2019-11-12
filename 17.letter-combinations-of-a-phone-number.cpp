/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        string strs[] = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> ret;
        map<char,string> mp;
        vector<int> p;
        for(int i=2;i<=9;i++)mp[char(i)+'0']=strs[i-2];
        for(int i=0;i<digits.size();i++)p.push_back(0);
        bool flag=true;
        if(digits=="")return ret;
        while(flag){
            string str="";
            for(int i=0;i<p.size();i++)str += mp[digits[i]][p[i]];
            ret.push_back(str);
            int index = p.size()-1;
            while(true){
                p[index]++;
                if(p[index]==mp[digits[index]].size()){
                    if(index==0){flag=false;break;}
                    p[index] = 0;
                    index--;
                }
                else break;
            }
        }
        return ret;
    }
};
