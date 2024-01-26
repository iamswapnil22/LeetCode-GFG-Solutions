# [Min Coin](https://www.geeksforgeeks.org/problems/min-coin5549/1)

```
class Solution{
	public:
	int MinCoin(vector<int>nums, int amount)
	{
	    int n = nums.size();
	    int dp[n+1][amount+1];
	
	    for(int i=0;i<=n;i++)
	    {
	        dp[i][0] = 0;
	    }
	    
	     for(int j=0;j<=amount;j++)
	    {
	        dp[0][j] = 1e9;
	    }
	   // dp[0][0] = 
	   
	   for(int i=1;i<n+1;i++)
	   {
	       for(int j=1;j<amount+1;j++)
	       {
	           if(nums[i-1] <= j)
	           {
	               dp[i][j] = min( 1+dp[i][j-nums[i-1]] , dp[i-1][j]);
	           }
	           else
	               dp[i][j] = dp[i-1][j];
	       }
	   }
         return ((dp[n][amount] == 1e9) ? -1 : dp[n][amount]);  

	} 
};
```
