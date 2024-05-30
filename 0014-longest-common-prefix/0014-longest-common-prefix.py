class Solution(object):
    def longestCommonPrefix(self, arr):
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
        return ans