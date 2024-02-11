# [Minimum Insertion Steps to Make a String Palindrome](https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/description/)

```
class Solution {
public:
    int minInsertions(string str1) {
        string str2 = str1;
        reverse(str1.begin(),str1.end());

        int n = str1.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(str1[i-1] == str2[j-1])
                {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return n-dp[n][n];
    }
};

```
