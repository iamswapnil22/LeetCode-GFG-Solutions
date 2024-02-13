# [Find First Palindromic String in the Array](https://leetcode.com/problems/find-first-palindromic-string-in-the-array/description/?envType=daily-question&envId=2024-02-13)

```
class Solution {
public:
    bool ispalindromic(string str)
    {  
        int i=0;
        int j=str.size()-1;

        while(i<=j)
        {
            if(str[i] != str[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        for(int i=0;i<words.size();i++)
        {
            if(ispalindromic(words[i])==true)
                return words[i];
        }
        return "";
    }
};
```

```
class Solution {
public:
    
    string firstPalindrome(vector<string>& words) {
        for(int i=0;i<words.size();i++)
        {
            string temp = words[i];
            reverse(temp.begin(),temp.end());
            if(temp == words[i])
                return words[i];

        }
        return "";
    }
};
```
