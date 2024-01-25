# [Rod Cutting](https://www.geeksforgeeks.org/problems/rod-cutting0840/1)

```

class Solution{
  public:
    int cutRod(int price[], int n) {
        int piece[n];
        for(int i=0;i<n;i++)
            piece[i]=i+1;
        
        
        //piece array
        //price array
        //n capacity
        
        
        int dp[n+1][n+1];
        
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=n;j++)
            {
                dp[i][j] = 0;
            }
        }
        
        
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(piece[i-1] <= j){
                
                    dp[i][j] = max( dp[i-1][j] , price[i-1]+dp[i][j-piece[i-1]]);        
                }
                else
                {
                    dp[i][j] = dp[i-1][j];    
                }
            
            }
        }
        
        
        return dp[n][n];
        
    }
};
```
