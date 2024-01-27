# [Minimum number of deletions and insertions](https://www.geeksforgeeks.org/problems/minimum-number-of-deletions-and-insertions0209/1)

```
class Solution{
	public:
	int minOperations(string str1, string str2) 
	{ 
	    int n = str1.size();
	    int m = str2.size();
	    
	   // int dp[n+1][m+1];
	    
	    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
	    
	    for(int i=1;i<=n;i++)
	    {
	        for(int j=1;j<=m;j++)
	        {
	            dp[i][j] = (str1[i-1] == str2[j-1]) ? 1 + dp[i-1][j-1] : max(dp[i][j-1],dp[i-1][j]);
	        }
	    }
	    
	    
	   return (n-dp[n][m])+(m-dp[n][m]);
	} 
};
```
