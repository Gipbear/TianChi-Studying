#include<bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

// @lc code=start
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(string t : tokens){
            int val;
            // 如果是数字则入栈
            if (isdigit(t.back())){
                val = stoi(t);
                s.push(val);
            }
            // 否则是符号，则取出栈顶两个元素进行计算，并将结果入栈
            else{
                int b = s.top(); s.pop();
                int a = s.top(); s.pop();
                if(t == "+") s.push(a+b);
                else if(t == "-") s.push(a-b);
                else if(t == "*") s.push(a*b);
                else if(t == "/") s.push(a/b);
            }
        }
        return s.top();
    }
};
// @lc code=end

