![image](https://github.com/iamswapnil22/LeetCode-GFG-Solutions/assets/95163993/a2953283-16e5-43f7-bc21-538d90c93d12)

move to leaf nodes exchange them recursively

```
class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* node) {
        if(node == nullptr)
            return;
        else
        {    
            mirror(node->left);
            mirror(node->right);
            
            Node* temp = node->left;
            node->left = node->right;
            node->right = temp;
            
        }
    }
};
```
