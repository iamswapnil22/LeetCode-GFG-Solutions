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

<---

<p font="consolas"> //int temp = 1 + solve(str,i,k) + solve(str,k+1,j);<br>
At this line we add 1 after each partition <br>
if string is already palindrome we don;t need to further partition<br>
and min to find minimum partition

--->

</p>


### WITH EVERY LINE DETAILS
```
#include <bits/stdc++.h>
using namespace std;
 
// Function to Check if a substring is a palindrome
bool isPalindrome(string String, int i, int j)
{
    while (i < j) {
        if (String[i] != String[j])
            return false;
        i++;
        j--;
    }
    return true;
}
 
// Function to find the minimum number of cuts needed for
// palindrome partitioning
int minPalPartion(string String, int i, int j)
{
    // Base case: If the substring is empty or a palindrome,
    // no cuts needed
    if (i >= j || isPalindrome(String, i, j))
        return 0;
 
    int ans = INT_MAX, count;
 
    // Iterate through all possible partitions and find the
    // minimum cuts needed
    for (int k = i; k < j; k++) {
        count = minPalPartion(String, i, k)
                + minPalPartion(String, k + 1, j) + 1;
        ans = min(ans, count);
    }
 
    return ans;
}
 
// Driver code
int main()
{
    string str = "ababbbabbababa";
 
    // Find the minimum cuts needed for palindrome
    // partitioning and display the result
    cout
        << "Min cuts needed for Palindrome Partitioning is "
        << minPalPartion(str, 0, str.length() - 1) << endl;
 
    return 0;
}

```
