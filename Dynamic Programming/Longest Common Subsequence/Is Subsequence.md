! [Is Subsequence](https://leetcode.com/problems/is-subsequence/)

Although this is an easy problem but the important thing is that we have give two strings namely a and b and we need to check whether the a string is subsequence of b.
so baiscally as per regular lcs the length of a string which we need to check as subsequence will be similar to lenght of subsequence we can calculate then we return true else false; and done...



```
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();

        if(n == 0 && m == 0)
            return true;
        if(m == 0)
            return false;
        
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));

        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<m+1;j++)
            {
                
                    dp[i][j] = (s[i-1] == t[j-1]) ? 1 + dp[i-1][j-1] : max(dp[i][j-1] , dp[i-1][j]);
                
            }
        }

        if(dp[n][m] != n && dp[n][m] != m )
            return false;
        else
            return true;
    }
};
```
