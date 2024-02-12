# [GFG Diameter of Binary tree](https://www.geeksforgeeks.org/problems/diameter-of-binary-tree/1)

```
class Solution {
  public:
    // Function to return the diameter of a Binary Tree.
    int solve(Node* root,int &res)
    {
        if(root==nullptr)
            return 0;
        
        
        int left = solve(root->left,res);
        int right = solve(root->right,res);
        
        int temp = 1 + max(left,right);
        int ans = 1+ left+ right;
        res = max(res,ans);
        return temp;
    }
    
    int diameter(Node* root) {
        int res = INT_MIN;
        solve(root,res);
        return res;
    }
};
```
