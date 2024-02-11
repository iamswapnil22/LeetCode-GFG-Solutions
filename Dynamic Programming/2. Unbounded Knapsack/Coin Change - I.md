# [Coin Change I](https://www.geeksforgeeks.org/problems/coin-change2448/1)

```
class Solution {
  public:
    long long int count(int coins[], int N, int sum) {

        long long dp[N+1][sum+1];
        
        
        for(int j=0;j<=sum;j++)
        {
            dp[0][j] = 0;
        }
        
        
        for(int i=0;i<=N;i++)
        {
            dp[i][0] = 1;
        }
            
        
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=sum;j++)
            {
                
                if(coins[i-1] <= j)
                {
                    dp[i][j] = dp[i-1][j]+dp[i][j-coins[i-1]];
                }
                else
                    dp[i][j] = dp[i-1][j];
                
            }
        }
        return dp[N][sum];
    }
};
```
