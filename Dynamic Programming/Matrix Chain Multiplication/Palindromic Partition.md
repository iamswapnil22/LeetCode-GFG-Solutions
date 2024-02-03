# [Palindromic Partition](https://www.geeksforgeeks.org/problems/palindromic-patitioning4845/1)

```
class Solution{
public:
    int dp[501][501];
    bool ispalindromic(string &str,int i,int j)
    {
        while(i<=j)
        {
            if(str[i] != str[j])
                return false;
            else
                {
                    i++;
                    j--;
                }
              
        }
        return true;
    }
    
    int solve(string &str,int i,int j)
    {
        if(i>=j)
        {
            return 0;
        }
        
        if(dp[i][j] != -1)
            return dp[i][j];
            
        if(ispalindromic(str,i,j))
            return 0;
        
        int m = INT_MAX;
        for(int k=i;k<=j-1;k++)
        {
            int temp = 1 + solve(str,i,k) + solve(str,k+1,j);
            if(m > temp)
                m = temp;
        }
        
        dp[i][j] = m;
        return dp[i][j];
        
        
    }
    int palindromicPartition(string str)
    {
        memset(dp,-1,sizeof(dp));
        return solve(str,0,str.size()-1);
    }
};
```
