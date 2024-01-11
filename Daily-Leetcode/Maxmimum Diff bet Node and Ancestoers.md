# [Maxmimum Diff bet Node and Ancestoers](https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/description/?envType=daily-question&envId=2024-01-11)

Brute force By traversing each root node and child node.

<img width="492" alt="image" src="https://github.com/iamswapnil22/LeetCode-GFG-Solutions/assets/95163993/5f18425c-6119-4195-9221-a0cd6e1ab319">
<br>
Optimal Solution to find Max Diff of NODE AND ANCESTOR
<br>

```
class Solution {
public:

    int maxANS = 0;

    int maxDiff(TreeNode* root,int minV,int maxV)
    {
        if(root == nullptr)
           { 
                return abs(minV-maxV);
            }

        minV = min(minV,root->val);
        maxV = max(maxV,root->val);

        int l = maxDiff(root->left,minV,maxV);
        int r = maxDiff(root->right,minV,maxV);
        return max(l,r);
    } 
    int maxAncestorDiff(TreeNode* root) {
        maxANS = maxDiff(root,INT_MAX,INT_MIN);
        return maxANS;
    }
};
```
