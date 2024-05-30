```
class Solution:
    def longestCommonPrefix(self, arr, n):
        ans = ""
        
        for i in range(len(arr[0])):
            ch = arr[0][i]
            flag = True
            for j in range(1,len(arr)):
                if i >= len(arr[j]) or ch != arr[j][i]:
                    flag = False
                    break
            
            if flag:
                ans+=ch
            else:
                break
        if ans == "":
            return "-1"
        else:
            return ans
```
