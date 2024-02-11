# [Target Sum](https://leetcode.com/problems/target-sum/)

<p align='left'> The Problem i not that hard i can't solve this question on GFG but On leetcode it accepts all test cases</p>
<p> The Main idea is similar to Subset with difference <br> we are given array of n size and we need to find the target sum by using + and - operator 

so in above example sum of arr = 7  and target is 1 we need to determing size for other dimension of dp matrix and it is don't by (target+sum)/2 which means if s1 =  4 then to acieve target 1 we need to find all subset whose sum is 3 and that's it we are done
 </p>

<img width="666" alt="image" src="https://github.com/iamswapnil22/LeetCode-GFG-Solutions/assets/95163993/eccb0bc5-385c-401f-890b-a13e99f2c4d7">

```
 class Solution{
     public:
        int mod = 1e9+7;
    int countSubsets(vector<int> &arr,int n,int m)
    {
        int dp[n+1][m+1];
        
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(i==0) dp[i][j] = 0;
                if(j==0) dp[i][j] = 1;
            }
        }
        
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(arr[i-1] <= j)
                {
                    dp[i][j] = dp[i-1][j-arr[i-1]]%mod + dp[i-1][j]%mod;
                }
                else
                    dp[i][j] = dp[i-1][j]%mod;
            }
        }
        return dp[n][m]%mod;
        
    }
    

    int findTargetSumWays(vector<int>& nums, int target)
    {
         target=abs(target);
         int n=nums.size();
         int sum=0;

         for(int i=0; i<n; i++)
             sum+=nums[i];

        int M=(sum+target)/2;
        if(sum<target||(sum+target)%2!=0)
            return 0;
        
         return countSubsets(nums, n, M);
    }
};
```
