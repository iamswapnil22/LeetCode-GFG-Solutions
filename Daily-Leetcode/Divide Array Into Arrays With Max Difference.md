# [Divide Array Into Arrays With Max Difference](https://leetcode.com/problems/divide-array-into-arrays-with-max-difference/submissions/?envType=daily-question&envId=2024-02-01)

```
class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());

        int n = nums.size();
        vector<vector<int>>  result;
        for(int i = 0; i<n; i+= 3 )
        {
            if(nums[i+2] - nums[i] > k)
            {
                return {};
            }
            result.push_back({nums[i],nums[i+1],nums[i+2]});
        }
        return result;


    }
};



// sort the element 

// if difference between first element and third element is greater than give k return {}
//else pushback all three elements in one pass for nested array. and done 
```
