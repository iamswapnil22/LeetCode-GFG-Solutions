```
class Solution
{
  public:
    char firstRep (string s)
    {
        unordered_map<char,int> mp;
        
        for(char ch:s)
        {
            mp[ch]++;
        }
        
        for(char ch:s)
        {
            if(mp[ch]>=2)
                return ch;
        }
        
        return '#';
    }
};
```
