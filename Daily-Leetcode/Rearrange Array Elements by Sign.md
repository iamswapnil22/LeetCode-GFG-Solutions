# [Rearrange Array Element by Sign](https://leetcode.com/problems/rearrange-array-elements-by-sign/description/)
    The Problem said that we have give array of equal sign of positve and negative element with even elements 
    wee need to rearrange in such a way that first elemment must be positive and secomd must be neagtive by 
    maintaining the order in original array.


```
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n,0);
        int nIndex = 1, pIndex = 0;

        for(int i = 0; i < n; i++){
            if(nums[i] < 0){
                res[nIndex] = nums[i];
                nIndex += 2;
            }
            else{
                res[pIndex] = nums[i];
                pIndex += 2;
            }
        }

        return res;
        

    }
};
```
