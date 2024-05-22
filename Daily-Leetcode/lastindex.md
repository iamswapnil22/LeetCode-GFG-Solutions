```
class Solution{
    public:
    int lastIndex(string s) 
    {
        int last = -1;
        int i=0;
        for(char ch:s)
        {
            if(ch=='1')
                last = i;
            i++;
        }
        return last;
    }

};
```
