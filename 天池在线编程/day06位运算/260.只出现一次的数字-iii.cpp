#include<bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=260 lang=cpp
 *
 * [260] 只出现一次的数字 III
 */

// @lc code=start
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // 得到两个不同值的异或
        int two = 0;
        for(int n : nums){
            two ^= n;
        }
        // 防止最小负数溢出，并使用&运算获得最低位的1
        int diff = (two == INT_MIN ? two : two & -two);
        // 再次遍历取异或，将该位含1的数为一个，不含的为另一个
        int n1 = 0, n2 = 0;
        for(int n : nums){
            if(n & diff)
                n1 ^= n;
            else
                n2 ^= n;
        }
        return {n1, n2};
    }
};
// @lc code=end

