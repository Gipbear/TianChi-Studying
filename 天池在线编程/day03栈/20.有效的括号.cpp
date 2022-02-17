#include<bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        // 用数组模拟栈
        vector<char> s_stack;
        for(char ch : s){
            // 栈空则直接加入栈顶
            if(s_stack.empty()){
                s_stack.push_back(ch);
                continue;
            }
            // 栈尾匹配则出栈，否则入栈
            if(ch-s_stack.back() == 1 || ch-s_stack.back() == 2){
                s_stack.pop_back();
            }
            else{
                s_stack.push_back(ch);
            }
        }
        if(s_stack.empty())
            return true;
        return false;
    }
};
// @lc code=end

