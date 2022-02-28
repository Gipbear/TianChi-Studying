#include<bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=811 lang=cpp
 *
 * [811] 子域名访问计数
 */

// @lc code=start
class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string,int>ump;
        for(auto str:cpdomains){
            // 提取数字
            int cnt=0;
            string temp="";
            for(auto c:str){
                if(c==' '){
                    cnt=stoi(temp);
                    temp="";
                    break;
                }
                temp+=c;
            }
            reverse(str.begin(),str.end());
            for(auto c:str){
                if(c==' '){
                    break;
                }
                if(c=='.'){
                    string temp1=temp;
                    reverse(temp1.begin(),temp1.end());
                    ump[temp1]+=cnt;
                }
                temp+=c;
            }
            reverse(temp.begin(),temp.end());
            ump[temp]+=cnt;
        }
        vector<string>res;
        for(auto e:ump){
            res.push_back(to_string(e.second)+' '+e.first);
        }
        return res;
    }
};
// @lc code=end

