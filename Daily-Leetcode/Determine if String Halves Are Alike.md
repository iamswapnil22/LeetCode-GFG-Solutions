# [Determine if String Halves Are Alike](https://leetcode.com/problems/determine-if-string-halves-are-alike/?envType=daily-question&envId=2024-01-12)

### Both Are Same Approach


```
class Solution {
public:
    bool isVowel(char ch)
    {
        if(ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch =='U')
            return true;
        else if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch =='u')
            return true;
        else
            return false;      
        
    }


    bool halvesAreAlike(string s) {
        //transform(s1.begin(), s1.end(), s1.begin(), ::tolower); 
        int i = 0;
        int j = s.size()/2;
        int lans = 0;
        int rans = 0;

        while(i <= s.size()/2 && j< s.size())
        {
            if(isVowel(s[i]))
                lans++;
            
            if(isVowel(s[j]))
                rans++;
            
            i++;
            j++;
        }

        if(lans == rans)
            return true;
        else
            return false;

    }
};
```



```
class Solution {
public:
    bool halvesAreAlike(string s) {
        int cnt = 0,n = s.size();
        transform(s.begin(), s.end(), s.begin(), ::tolower); 
        for(int  i = 0;i<n;i++)
        {
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
                cnt++;
        }
        int c = 0;
        for(int i = 0;i<n/2;i++)
        {
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
                c++;
        }
        if(2*c==cnt)
            return true;
        else
            return false;
    }
};
```
