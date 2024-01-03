# [2125 Number of Laser Beams in Bank](https://leetcode.com/problems/number-of-laser-beams-in-a-bank/?envType=daily-question&envId=2024-01-03)

## Using two Variables
```
class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
    int temp1 = 0;
    int ans = 0;

    for (auto x : bank) 
    {
        int temp2 = count(begin(x), end(x), '1');
        if (temp2 != 0) {
            ans += temp1 * temp2;
            temp1 = temp2;
        }
    }
    return ans;
}
};
```
## USING QUEUE
```
class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        queue<int> q;
        int n = bank.size();
        int m = bank[0].size();

        int res  = 0;
        for(int i=0;i<n;i++)
        {
            int temp = 0;
            for(int j=0;j<m;j++)
            {
                if(bank[i][j]=='1')
                    temp++;
            }
            if(temp != 0)
                q.push(temp);
        }
        cout<<q.size();
        while(!q.empty() && q.size() != 1)
        {
          int f = q.front();
          q.pop();

          int s = q.front();
          //q.pop();

            int pro = f * s;   
            res = res+pro;
           }
        
        return res;
    }
};
```

<p>
Here, the problem is that we need to calculate total beams in each row and multiply every totalbeams, which is previous row, and then add total sum to one variable and return it and all set
</p>