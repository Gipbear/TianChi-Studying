#include<bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=771 lang=cpp
 *
 * [771] 宝石与石头
 */

// @lc code=start
class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> m;
        for(char j : jewels)
            m.insert(j);
        int cnt = 0;
        for(char s : stones){
            if(m.count(s))
                cnt++;
        }
        return cnt;
    }
};
// @lc code=end

