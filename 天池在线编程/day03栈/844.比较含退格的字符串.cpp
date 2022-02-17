#include<bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=844 lang=cpp
 *
 * [844] 比较含退格的字符串
 */

// @lc code=start
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        // 使用字符串模拟栈
        string s_stack, t_stack;
        for(char ch : s){
            if(ch != '#')
                s_stack.push_back(ch);
            else if(!s_stack.empty())
                s_stack.pop_back();
        }
        for(char ch : t){
            if(ch != '#')
                t_stack.push_back(ch);
            else if(!t_stack.empty())
                t_stack.pop_back();
        }
        if(s_stack == t_stack)
            return true;
        return false;
    }
};
// @lc code=end

