the solution need to be in log(n) but below one is in  O(n)
```
class Solution {
  public:
    vector<int> firstAndLast(vector<int> &arr, int n, int x) {
        vector<int> res;
        
        for(int i=0;i<n;i++)
        {
            if(arr[i] == x)
            {
                res.push_back(i);
            }
        }
        
        if(res.size() == 0)
            return {-1};
        
        return {res[0],res[res.size()-1]};
        
    }
};
```
