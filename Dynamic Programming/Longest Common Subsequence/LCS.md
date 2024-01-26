# []()

```
class Solution
{
    
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int n, int m, string s1, string s2)
    {
        if(n == 0 || m == 0)
            return 0;
        
        
        if(s1[n-1] == s2[m-1])
        {
            //if last element of both string is same reduce both length -1 
            //if not the (a - 1 & b)  or (a & b-1) and recursive
            return 1 + lcs(n-1,m-1,s1,s2); 
        }
        else
        {
            // as we no we have to find longest which means maximum 
            //so that we use max between which function return max value;
            return max(lcs(n,m-1,s1,s2), lcs(n-1,m,s1,s2));
        }
    }
};
```