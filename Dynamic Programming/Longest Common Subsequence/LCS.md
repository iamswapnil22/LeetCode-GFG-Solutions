# [Longest Commmon Subsequence](https://www.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1)

## TLE Recursive Sol
```
class Solution
{
    
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int n, int m, string s1, string s2)
    {
        if(n == 0 || m == 0)
            return 0;
        
        
        if(s1[n-1] == s2[m-1])
        {
            //if last element of both string is same reduce both length -1 
            //if not the (a - 1 & b)  or (a & b-1) and recursive
            return 1 + lcs(n-1,m-1,s1,s2); 
        }
        else
        {
            // as we no we have to find longest which means maximum 
            //so that we use max between which function return max value;
            return max(lcs(n,m-1,s1,s2), lcs(n-1,m,s1,s2));
        }
    }
};
```

## DP Memoization

```
class Solution
{
    
    public:
    //Function to find the length of longest common subsequence in two strings.
    int Memo(int n, int m, string &s1, string &s2,vector<vector<int>> &dp)
    {
        
        if(n == 0 || m == 0)
            return 0;
        
        if(dp[n][m] != -1)  // this return solution for subproblems rather than computing ag
            return dp[n][m];

        
        if(s1[n-1] == s2[m-1])
        {
            //if last element of both string is same reduce both length -1 
            //if not the (a - 1 & b)  or (a & b-1) and recursive
            dp[n][m] = 1 + Memo(n-1,m-1,s1,s2,dp); 
            return dp[n][m];
        }
        else
        {
            // as we no we have to find longest which means maximum 
            //so that we use max between which function return max value;
            dp[n][m] =  max(Memo(n,m-1,s1,s2,dp), Memo(n-1,m,s1,s2,dp));
            return dp[n][m];
        }
    }
    
    int lcs(int n, int m, string s1, string s2)
    {
        //vector<int> dp(n+1,vector<int>(m+1,-1));
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return Memo(n,m,s1,s2,dp);
    }
};

```

## Tabulation Bottom Up Approach

```
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        int dp[n+1][m+1];
        
        for(int i=0;i<=n;i++)
            dp[i][0] = 0;
        
        for(int j=0;j<=m;j++)
            dp[0][j] = 0;
        

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                dp[i][j] = (text1[i-1] == text2[j-1]) ? 1+dp[i-1][j-1] : max(dp[i][j-1] , dp[i-1][j]);
            }
        }
         return dp[n][m];
    }
};
```
