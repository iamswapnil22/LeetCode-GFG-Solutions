# [Perfect Squares](https://leetcode.com/problems/perfect-squares/?envType=daily-question&envId=2024-02-08)


## TOP DOWN :
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


## BOTTOM UP:

```
class Solution {
public:
    int numSquares(int n) {
        vector <int> dp(n+1, INT_MAX);
        dp[0] = 0;
        for(int sq=1; sq<=n; sq++) {
            // sq is the current number to be checked
            for(int i=1; i*i<=sq; i++) {
                dp[sq] = min(dp[sq], dp[sq-(i*i)]+1);
            }
        }
        return dp[n];
    }
};
```
