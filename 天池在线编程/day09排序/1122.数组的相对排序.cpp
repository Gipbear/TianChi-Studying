#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=1122 lang=cpp
 *
 * [1122] 数组的相对排序
 */

// @lc code=start
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int n1 = arr1.size(), n2 = arr2.size();
        // 统计arr1中每个数字出现的次数
        vector<int> cnt(1001);
        for(int a1 : arr1){
            cnt[a1]++;
        }
        // 将arr2中的每个数字重复放入arr1中
        int i = 0;
        for(int a2: arr2){
            while(cnt[a2] > 0){
                arr1[i] = a2;
                i++;
                cnt[a2]--;
            }
        }
        // 剩下的依次放入即可
        for(int j = 0; j < cnt.size(); j++){
            while(cnt[j] > 0){
                arr1[i] = j;
                i++;
                cnt[j]--;
            }
        }
        return arr1;
    }
};
// @lc code=end

