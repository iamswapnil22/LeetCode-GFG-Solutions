# [Knapsack with Duplicate Items](https://www.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1)

It is simple as 0/1 the main difference is that one item can be add to bag multiple times to maximize the profit 

ex. if we have in super market to still product if there is gold silver and bronze then rather than selecting every item once we choose gold more than once to maximize the profit.
that's it donneeee......

```
class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        int dp[N+1][W+1];
        
        for(int i=0;i<=N;i++)
        {
            for(int j=0;j<=W;j++)
            {
               // if(i==0 || j == 0)
                    dp[i][j] = 0;
            }
        }
        
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=W;j++)
            {
                if(wt[i-1] <= j)
                {
                    dp[i][j] = max(val[i-1]+dp[i][j-wt[i-1]],dp[i-1][j]);
                }
                else
                    dp[i][j] = dp[i-1][j];
                
            }
        }
        return dp[N][W];
    }
};
```
