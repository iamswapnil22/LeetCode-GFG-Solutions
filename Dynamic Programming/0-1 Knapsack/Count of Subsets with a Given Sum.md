# [Count of Subsets with a Given Sum](https://www.geeksforgeeks.org/problems/perfect-sum-problem5633/1)
# Revised J==0
```
class Solution{

	public:
	int perfectSum(int arr[], int n, int sum)
	{
        int mod=1e9+7;
	    int dp[n+1][sum+1];
        
         for(int i=0;i<sum+1;i++)
	        dp[0][i] = 0;
	     //setting zero to first row
	     
	     for(int i=0;i<n+1;i++)
	        dp[i][0] = 1;
        //setting one to first column
	    
	    
	    for(int i=1;i<=n;i++)
	    {
	        for(int j=0;j<=sum;j++) // j==0
	        {
	            
	            if(arr[i-1] <= j)
	            {
	                dp[i][j] = dp[i-1][j-arr[i-1]]%mod + dp[i-1][j]%mod;
	            }
	            else
	                dp[i][j] = dp[i-1][j]%mod;
	        }
	    }
	    return dp[n][sum]%mod;
	}
	  
};
```
