# [Partition Equal Subset Sum](https://www.geeksforgeeks.org/problems/subset-sum-problem2014/1)

```
class Solution{
public:
    int equalPartition(int N, int arr[])
    {
        if(N <= 1)
            return 0;
        int sum = 0;
        for(int i=0;i<N;i++)
        {
            sum+=arr[i];
        }
        
        if(sum%2 != 0)
            return 0;
        
        sum = sum/2;
        bool dp[N+1][sum+1];
        
        for(int i=0;i<=N;i++)
        {
            for(int j=0;j<=sum;j++)
            {
                if(i==0)
                    dp[i][j] = false;
                
                if(j==0)
                    dp[i][j] = true;
            }
        }
        
        
        
        
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=sum;j++)
            {
                if(arr[i-1] <= j)//
                {
                  dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
                }
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        
        
        return dp[N][sum];   
    }
    
};
```
