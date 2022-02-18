#include<bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] 字符串解码
 */

// @lc code=start
class Solution {
public:
    string decodeString(string s) {
        stack<pair<int, string>> s_stack;
        int k = 0;
        string res = "";
        for(char ch : s){
            // 字符串转数字
            if(isdigit(ch)){
                k = k*10 + ch-'0';
            }
            // 遇到左括号，将已经合成的字符串res和括号前的数字k入栈
            // 并将数字和字符串清空
            else if(ch == '['){
                s_stack.push({k, res});
                res = "";
                k = 0;
            }
            // 遇到右括号，栈顶出栈，将目前的字符串res重复k倍，并加入原本的字符串中，合并为新的res
            else if(ch == ']'){
                int tmp_num = s_stack.top().first;
                string tmp_res = s_stack.top().second;
                s_stack.pop();
                while(tmp_num--){
                    tmp_res += res;
                }
                res = tmp_res;
            }
            // 单个字符直接加入res
            else{
                res += ch;
            }
        }
        return res;
    }
};
// @lc code=end

