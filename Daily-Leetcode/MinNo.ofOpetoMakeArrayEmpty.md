# [Minimum Number of Operation required to make array empty](https://leetcode.com/problems/minimum-number-of-operations-to-make-array-empty/submissions/?envType=daily-question&envId=2024-01-04)

```
class Solution {
public:
    int minOperations(vector<int>& nums) {
        map<int,int> mp;
        int count = 0;
        for(auto it:nums)
        {
            mp[it]++;
        }

        for(auto it:mp)
        {
            if(it.second == 1) return -1;
            
            count += it.second/3 + (it.second%3 > 0);
            
        }

        /*
        for(auto it:mp)
        {
            if(it.second==1)
            return -1;
            else if(it.second%3==0)
            x+=it.second/3;
            else
            x+=(it.second/3)+1;
        }
        */
        return count;
    }
};
```
#### Explanation
```
 if(it.second==1)
return -1;
else if(it.second%3==0)
x+=it.second/3;
else
x+=(it.second/3)+1;


x+=(it.second/3)+1; 
our code make elements of group of three even afre array contain even element

ex if 8%3 != 0
but as per condition we need to give priority to group of three
then 


we add 8/3 to result which is **2** which means 3 + 3 = 6 
8-6 = 2 
then for grp of two we add **1**


so finally we add 3 to result;
```
