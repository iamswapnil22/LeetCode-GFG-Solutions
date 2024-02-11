BELOW KNAPSACK PROBLEM IS SOLVED USING TABULATION BOTTOM UP APPROACH.


1. Start with Declaration.
   ```
   int dp[n+1][w+1];
   ```
2. Intialization of first row and first column.
   ```
   for(int i=0;i<=n;i++)
       {
           for(int j=0;j<=w;j++)
           {
               if(i==0 || j==0)
               {
                   dp[i][j] = 0;
               }
               // INIT Matrix with 0..0..0 to top row and left column. 
           }
       }
   ```
3. Filling the Matrix using 'i' & 'j'.
   ```
    for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=w;j++)
            {
                if(wt[i-1] <= j)
                {
                    dp[i][j] = max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
                }
                else if(wt[i-1] > j)
                    dp[i][j] = dp[i-1][j];
            }
        }
   ```  



## TABULATION CODE  
    
    class Solution
    {
        public:
        // DP - TABULATION 
        int knapSack(int w, int wt[], int val[], int n) 
        { 
           int dp[n+1][w+1];
           
           for(int i=0;i<=n;i++)
           {
               for(int j=0;j<=w;j++)
               {
                   if(i==0 || j==0)
                   {
                       dp[i][j] = 0;
                   }
                   // INIT Matrix with 0..0..0 to top row and left column. 
               }
           }
           
           
           for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=w;j++)
                {
                    if(wt[i-1] <= j)
                    {
                        dp[i][j] = max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
                    }
                    else if(wt[i-1] > j)
                        dp[i][j] = dp[i-1][j];
                }
            }
            
            return dp[n][w];
        }
    };
    
