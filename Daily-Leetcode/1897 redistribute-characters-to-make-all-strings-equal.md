# [1897 redistribute-characters-to-make-all-strings-equal](https://leetcode.com/problems/redistribute-characters-to-make-all-strings-equal)

```
class Solution {
public:
    bool makeEqual(vector<string>& words) {
        vector<int> vec(26,0);
        for(auto word:words)
        {
            for(auto ch:word)
            {
                vec[ch-'a']++;
            }
        }

        int n = words.size();
        for(int val:vec)
        {
            if(val%n != 0)
            {
                return false;
            }
        }
        return true;
    }
    
};
```


In the expression c - 'a', c is assumed to be a lowercase letter, and 'a' represents the ASCII value of the lowercase letter 'a'. The ASCII values of characters are consecutive integers, so subtracting the ASCII value of 'a' from the ASCII value of the character c gives you the position of the letter c in the alphabet. This is a common technique in programming to convert a character to its corresponding index in a zero-based index system.

For example:

If c is 'a', then 'a' - 'a' is 0.
If c is 'b', then 'b' - 'a' is 1.
If c is 'c', then 'c' - 'a' is 2.
