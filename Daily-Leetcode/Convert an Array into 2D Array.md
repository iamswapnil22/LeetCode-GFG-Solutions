# [2610 Convert an Array into 2D Array with Condition](https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions/description/?envType=daily-question&envId=2024-01-02)
### Both Approach Are Same

```
class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> ans;
        unordered_map<int, int> mp;
        for(auto i: nums){
            mp[i]++;
        }  

        while(!mp.empty()){
            vector<int> temp;
            for(auto it = mp.begin(); it != mp.end(); ){
                temp.push_back(it->first);
                it->second--;
                if(it->second == 0){
                    it = mp.erase(it);
                } else {
                    ++it;
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
```

```
class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        

        unordered_map<int,int> mp;
        
        for(int i:nums)
        {
            mp[i]++;
        }

        
        vector<vector <int>> ans;
        
         while(mp.size()) {
            vector<int> temp;
            for(auto i : mp) 
                temp.push_back(i.first);

            for(int i : temp) {
                if(!--mp[i]) 
                    mp.erase(i);
            }
            ans.push_back(temp);
        }
        return ans;
        
    }
};
```


the problem states that we have a 1d array ex {1,1,2,3,4,2,2,3};
in which frequency of 1 is 2 
                  and 2 is 3
                  and 3 is 2
                  and 4 is 1
we need to return a 2d array like -
        [
        [1,2,3,4],
        [1,2,3],
        [2]
        ]
that's it our ans must be reduced no.of rows in o/p matrix.
