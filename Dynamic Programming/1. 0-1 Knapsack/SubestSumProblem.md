# [Subset Sum Problem](https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1)


```
class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        
        bool dp[n+1][sum+1];
        
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=sum;j++)
            {
                if(i==0) dp[i][j] = false;
                
                if(j==0) dp[i][j] = true;
            }
        }
        
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=sum;j++)
            {
                if(arr[i-1] <= j)
                {
                    dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
                }
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        
        return dp[n][sum];
        
    }
};

```

### DP Matrix (Tabulation) 
<img width="570" alt="image" src="https://github.com/iamswapnil22/LeetCode-GFG-Solutions/assets/95163993/cb3bde6d-ab66-483e-a9f5-6f0a63f149e5">

### Main Logic to fill table:
<img width="570" alt="image" src="https://github.com/iamswapnil22/LeetCode-GFG-Solutions/assets/95163993/17e035a5-3ce3-474b-a9b4-d3d3f15fa870">

