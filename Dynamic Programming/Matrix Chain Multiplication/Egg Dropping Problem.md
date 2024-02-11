# [Super Egg Drop](https://leetcode.com/problems/super-egg-drop/)

### Memoization WORKS ON GFG NOT LEETCODE ERROR : Time Limit Exceeds.
```
class Solution
{
    int dp[201][201];
    vector<int> floors;
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    
    int solve(int e,int f)
    {
        if(f == 0 || f == 1)
            return f;
        
        if(e == 1)
            return f;
            
        if(dp[e][f] != -1)
            return dp[e][f];
        
        int ans = INT_MAX;
        for(int k=1;k<=f;k++)
        {
            int temp = 1 + max(solve(e-1,k-1),solve(e,f-k));
            ans = min(ans,temp);
        }
        return dp[e][f] = ans; 
    }
    
    int eggDrop(int e, int f) 
    {
        memset(dp,-1,sizeof(dp));
        return solve(e,f);
    }
};
```

### TABULATION TLE ON LEETCODE.

```
class Solution {
public:
    int superEggDrop(int e, int f) {

        int dp[e+1][f+1];

        for(int i=0;i<e+1;i++){
            dp[i][0] = 0;
            dp[i][1] = 1;
        }
        
        for(int i=0;i<f+1;i++) dp[1][i] = i;
        
        for(int i=2;i<e+1;i++)
        {
            for(int j=2;j<f+1;j++)
            {
                dp[i][j] = INT_MAX;
                for(int k=1;k<j+1;k++)
                {
                    int temp = 1 + max(dp[i-1][k-1],dp[i][j-k]);
                    dp[i][j] = min(dp[i][j],temp); 
                }
            }
        }
        return dp[e][f];
    }
};
```
