#include<bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=227 lang=cpp
 *
 * [227] 基本计算器 II
 */

// @lc code=start
class Solution {
public:
    int calculate(string s) {
        int res = 0;
        stack<int> numStack;
        // num计算"真"数字, sign标记该数字"前"的符号
        int num = 0, sign = '+';
        for(int i = 0; i < s.size(); i++){
            // 计算数字
            if(s[i] >= '0'){
                // 计算多位数(先减'0'防止int溢出)
                num = num*10 -'0' + s[i];
            }
            // 处理非空格或最后一个数字
            if((s[i] < '0' && s[i] != ' ') || i == s.size()-1){
                if(sign == '+')  // 正数直接加入
                    numStack.push(num);
                else if(sign == '-')  // 负数取反
                    numStack.push(-num);
                else{
                    // 乘除优先级最高, 直接与栈顶元素计算, 结果入栈.
                    int tmp;
                    if(sign == '*')
                        tmp = numStack.top() * num;
                    else
                        tmp = numStack.top() / num;
                    numStack.pop();
                    numStack.push(tmp);
                }
                sign = s[i];
                num = 0;
            }
        }
        // 栈内元素全部求和
        while(!numStack.empty()){
            res += numStack.top();
            numStack.pop();
        }
        return res;
    }
};
// @lc code=end

