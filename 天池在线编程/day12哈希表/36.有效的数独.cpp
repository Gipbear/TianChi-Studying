#include<bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */

// @lc code=start
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // 初始化为0，表示都没有出现过
        int col[9][10] = {0};
        int row[9][10] = {0};
        int box[9][10] = {0};
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.')
                    continue;
                int num = board[i][j]-'0';
                // 表示该数字在该位置出现过，直接返回false
                if(row[i][num]) return false;
                if(col[j][num]) return false;
                if(box[(i/3)*3 + j/3][num]) return false;
                
                // 否则标记该位置
                row[i][num] = 1;
                col[j][num] = 1;
                box[(i/3)*3+j/3][num] = 1;
            }
        }
        return true;
    }
};
// @lc code=end

