# [Super Egg Drop](https://leetcode.com/problems/super-egg-drop/)

### Memoization WORKS ON GFG NOT LEETCODE ERROR : Time Limit Exceeds.
```
class Solution
{
    int dp[201][201];
    vector<int> floors;
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    
    int solve(int e,int f)
    {
        if(f == 0 || f == 1)
            return f;
        
        if(e == 1)
            return f;
            
        if(dp[e][f] != -1)
            return dp[e][f];
        
        int ans = INT_MAX;
        for(int k=1;k<=f;k++)
        {
            int temp = 1 + max(solve(e-1,k-1),solve(e,f-k));
            ans = min(ans,temp);
        }
        return dp[e][f] = ans; 
    }
    
    int eggDrop(int e, int f) 
    {
        memset(dp,-1,sizeof(dp));
        return solve(e,f);
    }
};
```

### TABULATION TLE ON LEETCODE.

```
class Solution {
public:
    int superEggDrop(int e, int f) {

        int dp[e+1][f+1];

        for(int i=0;i<e+1;i++){
            dp[i][0] = 0;
            dp[i][1] = 1;
        }
        
        for(int i=0;i<f+1;i++) dp[1][i] = i;
        
        for(int i=2;i<e+1;i++)
        {
            for(int j=2;j<f+1;j++)
            {
                dp[i][j] = INT_MAX;
                for(int k=1;k<j+1;k++)
                {
                    int temp = 1 + max(dp[i-1][k-1],dp[i][j-k]);
                    dp[i][j] = min(dp[i][j],temp); 
                }
            }
        }
        return dp[e][f];
    }
};
```

### Approach which passed all test cases ✅
```
class Solution {
public:
    
    int superEggDrop(int K, int N) {
        if(N==0||N==1) return N;     //Think for base case
        if(K==1) return N;
        
        vector<vector<int>> dp(K+1,vector<int> (N+1,0));
      for(int i=0;i<=K;i++)
        dp[i][0]=0,dp[i][1]=1;   //Filling from base case as if N==0 ans=0 , N==1 ans=1
      for(int i=0;i<=N;i++)
        dp[0][i]=0,dp[1][i]=i;   //Filling from base case as if K==0 ans=0 , K==1 ans=N, number of current floor (i)
        
        for(int i=2;i<K+1;i++)
        {
            for(int j=2;j<N+1;j++)
            {    int l=1,h=j,temp=0,ans=100000;
                 while(l<=h)
                 {
                    int mid=(l+h)/2;
                    int left= dp[i-1][mid-1]; //egg broken check for down floors of mid
                    int right= dp[i][j-mid];  // not broken check for up floors of mid
                    temp=1+max(left,right);          //store max of both 
                    if(left<right){                  //since right is more than left and we need more in worst case 
                      l=mid+1;                       // so l=mid+1 to gain more temp for worst case : upward
                    }
                    else                             //left > right so we will go downward 
                    {    
                        h=mid-1;
                    }
                    ans=min(ans,temp);               //store minimum attempts
                 }
                 dp[i][j]=ans;
            }
        }
        return dp[K][N];
         
    }
};
```

### MOST PERFECT ANS ✅
```
class Solution {
public:


int memo[10001][101];

  int check(int k,int n){
         if(k==0||k==1){return k;}
         if(n==1){return k;}
         if(memo[k][n]!=-1){
               return memo[k][n];
         }
         int st=1; int en=k;


        int ans=INT_MAX;
         while(st<=en){

              int mid=(st+en)/2;
              int broke=check(mid-1,n-1);
              int notbroke=check(k-mid,n);
              int temp=1+max(broke,notbroke);
              if(broke>notbroke){
                   en=mid-1;


              }
              else{
                    st=mid+1;

              }
              ans=min(ans,temp);
         }
       return    memo[k][n]=ans;


  }
    int superEggDrop(int k, int n) {
        swap(n,k);
          for(int i=0;i<=10000;i++){
                for(int j=0;j<=100;j++){
                    memo[i][j]=-1;
                }
          }

        //   //for me k=number of floors, n=number of eggs

        return check(k,n);
       
    }
};
```
