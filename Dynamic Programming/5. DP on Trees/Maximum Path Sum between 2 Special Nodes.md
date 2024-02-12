# [Maximum Path Sum between 2 Special Nodes](https://www.geeksforgeeks.org/problems/maximum-path-sum/1)

```
class Solution {
public:
    int sum = INT_MIN;
   int findMaxPathSum(Node *root)
   {
     if (!root)
       return 0;
   
     int lsum = findMaxPathSum(root->left);
     int rsum = findMaxPathSum(root->right);
     
     if (!root->left and !root->right)
       return root->data;
       
     if (!root->left)
       return root->data + rsum;
       
     if (!root->right)
       return root->data + lsum;
       
     sum = max(sum, root->data + lsum + rsum);
     return max(root->data + lsum, root->data + rsum);
   }
   
   int maxPathSum(Node *root)
   {
     int ans = findMaxPathSum(root);
     if(!root->left or !root->right)
           sum = max(sum, ans);
     return sum;
   }
};

```
