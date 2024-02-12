# [Maximum path sum from any node]()
      int res = INT_MIN;
        solve(root,res);
        return res;
      This INT_MIN IMPACT A LOT


```
class Solution {
  public:
    //Function to return maximum path sum from any node in a tree.
    int solve(Node*root, int &res)
    {
        if(root == nullptr)
            return 0;
        
        int left = max(0,solve(root->left,res));
        int right = max(0,solve(root->right,res));
        
        root->data + max(left,right);
        
        
        res = max(res,root->data+left+right);
        
        return root->data + max(left,right);
    }
    
    
    int findMaxSum(Node* root)
    {
        int res = INT_MIN;
        solve(root,res);
        return res;
    }
};
```
