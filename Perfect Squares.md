# [Perfect Squares](https://leetcode.com/problems/perfect-squares/?envType=daily-question&envId=2024-02-08)

```
class Solution {
public:
    int dp[10001];

    int squur(int n) {
        
        if(n == 0)
            return 0;


        if(dp[n] != -1)
            return dp[n];


        int mincount = INT_MAX;

        for(int i=1;i*i<=n;i++)
        {
            mincount = min(mincount,1 + squur(n-i*i));
        }
        return dp[n] = mincount;
    }

    int numSquares(int n) {
     memset(dp,-1,sizeof(dp));
     return squur(n);   
    }
};
```
