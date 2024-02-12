# [Binary Tree Maximum Path Sum](https://leetcode.com/problems/binary-tree-maximum-path-sum/)

### Using Recursion

``int left = max(0, solve(root->left,res)); // we are checking left-subtree max path sum & if function returns negative then we can use 0;
``
<br>
`int temp = max(left,right)+root->val;  // if the path doesn't go through it's parent node the it return maximum path sum between left and right subtree and add it own value and send it to parent node`
<br>
`int ans = left+right+root->val; if parent node is between left and right subtree then we return left subtree path sum value + right subtree pathsum value and the root node value and done`

<img width="305" alt="image" src="https://github.com/iamswapnil22/LeetCode-GFG-Solutions/assets/95163993/2b8b9bfd-44b0-471f-954c-e2d6fadda130">

```
class Solution {
public:
    int solve(TreeNode* root,int &res)
    {
        if(root == nullptr)
            return 0;
        
        int left = max(0, solve(root->left,res));
        int right =max(0, solve(root->right,res));


         int temp = max(left,right)+root->val;
         int ans = left+right+root->val;
         res = max(res,ans);
         return temp; 

    }

    int maxPathSum(TreeNode* root) {
        int val = INT_MIN;
        solve(root,val);
        return val;
    }
};
```
