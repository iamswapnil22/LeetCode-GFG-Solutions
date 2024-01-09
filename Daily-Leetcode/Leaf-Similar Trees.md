# [872. Leaf Similar Tree](https://leetcode.com/problems/leaf-similar-trees/description/?envType=daily-question&envId=2024-01-09)

<h2>
Apporoach 1 Using Inorder Traversal
</h2>

```
class Solution {
public:
    
    void inorder(TreeNode* root,vector<int> &vec)
    {
        if(root == nullptr)
            return;
        
        inorder(root->left,vec);

        if(root->left == nullptr && root->right == nullptr)
        {
            vec.push_back(root->val);
        }
        inorder(root->right,vec);
    }

    void check(TreeNode* root)
    {

    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> vec1;
        vector<int> vec2;
        inorder(root1,vec1);
        inorder(root2,vec2);

        if(vec1.size() != vec2.size())
            return false;
        
        for(int i=0;i<vec1.size();i++)
        {
            if(vec1[i]!=vec2[i])
                return false;
        }
        return true;
        

    }
};
```



<h2>
Approach 2 Using Stack and Comparing each leaf node at the same time
</h2>

```
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        stack<TreeNode*> s1 , s2;
        s1.push(root1); s2.push(root2);
        while (!s1.empty() && !s2.empty())
            if (dfs(s1) != dfs(s2)) return false;
        return s1.empty() && s2.empty();
    }

    int dfs(stack<TreeNode*>& s) {
        while (true) {
            TreeNode* node = s.top(); s.pop();
            if (node->right) s.push(node->right);
            if (node->left) s.push(node->left);
            if (!node->left && !node->right) return node->val;
        }
    }
