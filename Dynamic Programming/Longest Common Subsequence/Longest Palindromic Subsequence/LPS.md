# [Longest Palindromic Subsequence](https://www.geeksforgeeks.org/problems/longest-palindromic-subsequence-1612327878/1)

we have only given one string and this is related to our lcs so we need two string.
but plot twist we want to find palindrome which means str1 : xaaabbb str2 : bbbaaax
we get string 2 from string 1 hurray and just one lcs and you are done


```
class Solution{
  public:
    int longestPalinSubseq(string str1) {
        string str2 = str1;
        reverse(str1.begin(),str1.end());
        
        int n = str1.size();  
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<n+1;j++)
            {
                if(str1[i-1] == str2[j-1])
                {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }
        return dp[n][n];
    }
};
```
