Not an optimal approach but still works good
```
class Solution {
  public:
    vector<int> Solve(int n, vector<int>& nums) {
       vector<int> res;
       unordered_map<int,int> mp;
       
       for(auto x:nums)
          mp[x]++;
       
       for(auto x:mp)
       {
           if(x.second > n/3)
           {
               res.push_back(x.first);
           }
       }
       sort(res.begin(),res.end());
       if(res.size() < 1)
            return {-1};
       else
            return res;
    }
};
```
