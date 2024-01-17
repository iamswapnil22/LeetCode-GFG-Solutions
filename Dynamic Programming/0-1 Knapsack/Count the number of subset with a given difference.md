# [Count the number of subset with a given difference](https://www.geeksforgeeks.org/problems/partitions-with-given-difference/1)

## [Dynamic Programming/0-1 Knapsack/Count of Subsets with a Given Sum.md] 
```class Solution {
  public:
    int countPartitions(int n, int diff, vector<int>& arr) {
        int mod = 1e9+7;
        
        int sum = 0;
        for(int it:arr)
            sum+=it%mod;
        
       
        if (sum-diff < 0 ||((diff + sum) % 2 != 0))
            return 0;
        
        int s1 = ((diff+sum)/2);
        
        vector<vector<int>> dp(n+1,vector<int>(s1+1));
        
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=s1;j++)
            {
                if(i==0) dp[i][j] = 0;
                if(j==0) dp[i][j] = 1;
            }
            
        }
        
        
        
        for(int i=1;i<n+1;i++)
        {
            for(int j=0;j<s1+1;j++)
            {
                if(arr[i-1] <= j)
                {
                    dp[i][j] = dp[i-1][j-arr[i-1]]%mod + dp[i-1][j]%mod;
                }
                else
                {
                    dp[i][j] = dp[i-1][j]%mod;
                }
            }
        }
        
        return dp[n][s1]%mod;
    }
};
```
