# 1438. Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit

```


class Solution(object):
    def longestSubarray(self, nums, limit):
        """
        :type nums: List[int]
        :type limit: int
        :rtype: int
        """
        sub = []
        longest = 0
        for i in range(0,len(nums)):
            for j in range(i+1,len(nums)+1):
                temp = nums[i:j]
                # print(temp)
                x = max(temp)
                y = min(temp)
                if abs(x-y) <= limit:
                    longest = max(longest,len(temp))
          
        return longest
```
