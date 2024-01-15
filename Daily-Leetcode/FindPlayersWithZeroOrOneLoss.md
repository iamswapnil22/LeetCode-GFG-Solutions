# [FindPlayersWithZeroOrOneLoss](https://leetcode.com/problems/find-players-with-zero-or-one-losses/description/?envType=daily-question&envId=2024-01-15)

```
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        
        vector<int> win;
        vector<int> los;
        map<int,int> los_mp;
        
        for(auto x:matches)
        {
           los_mp[x[1]]++; 
        }

        for(auto x:matches)
        {
           auto it = los_mp.find(x[0]);
           if(it == los_mp.end())
            {
                win.push_back(x[0]);
                los_mp[x[0]]=2;
            }
        
            if(los_mp[x[1]]==1)
                los.push_back(x[1]);
        }

        sort(win.begin(),win.end());
        sort(los.begin(),los.end());
        //vector<int> win(win_st.begin(),win_st.end());
        return {win,los};      
    }
};
```
