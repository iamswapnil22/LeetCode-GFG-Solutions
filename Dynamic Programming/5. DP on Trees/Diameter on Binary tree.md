# [Diameter on Binary Tree](https://leetcode.com/problems/diameter-of-binary-tree/)

```
class Solution {
public:

    int solve(TreeNode* root,int &res)
    {
        if(root == nullptr)
        {
            return 0;
        }

        int left = solve(root->left,res);
        int right = solve(root->right,res);

        int temp = 1 + max(left,right); // pass highest diameter from left or right subtree
        res = max(res,left+right); // overall ans
        return temp;

    }
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        solve(root,res);    
        return res;
    }
};
```
