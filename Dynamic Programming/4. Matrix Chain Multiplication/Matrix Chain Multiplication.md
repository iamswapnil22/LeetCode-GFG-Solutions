## Matrix Chain Multiplication - Basic Format for every problem

<img align="center" width="569" alt="image" src="https://github.com/iamswapnil22/LeetCode-GFG-Solutions/assets/95163993/7176ed16-448a-4e1d-b6e4-a27d34437c88">

## RECURSION

```
class Solution{
public:
    int solve(int arr[],int n,int i,int j)
    {
        if(i>=j)
            return 0;
        
        int min = INT_MAX;
        
        for(int k=i;k<=j-1;k++)
        {
            int temp = solve(arr,n,i,k) + solve(arr,n,k+1,j)
                        + (arr[i-1]*arr[k]*arr[j]);
            
            if(temp < min)
                min = temp;
        }
        
        return min;
    }
    int matrixMultiplication(int N, int arr[])
    {
        return solve(arr,N,1,N-1);
    }
};
```

## MEMOIZATION
```
class Solution{
public:
    int dp[1001][1001];
    
    int solve(int arr[],int n,int i,int j)
    {
        if(i>=j)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int min = INT_MAX;
        
        for(int k=i;k<=j-1;k++)
        {
            int temp = solve(arr,n,i,k) + solve(arr,n,k+1,j)
                        + (arr[i-1]*arr[k]*arr[j]);
            
            if(temp < min)
                min = temp;
        }
        dp[i][j] = min;
        return dp[i][j];
    }
    int matrixMultiplication(int N, int arr[])
    {
        memset(dp,-1,sizeof(dp));
        return solve(arr,N,1,N-1);
    }
};

```
