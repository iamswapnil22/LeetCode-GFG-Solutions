# [2385. Amount of time required to make Binary tree infected](https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/)
The Main Aim is we have a give tree and we need to go to every next node in 1 time. 
but in tree we can't go to upward(Parent Node) so firstly we need to convert the tree in to Adj.
List Which makes use easier basically in Graph form and we need to perform BFS on it by pushing next node to queue.

1. Level Order Traversal.
2. BFS on Parent HashMap created During LOT


```
class Solution {
public:
    int dobfs(map<TreeNode*,TreeNode*> &mp,TreeNode* targetNode)
    {
        map<TreeNode*,bool> vis;
        vis[targetNode] = 1;
        int time = 0;
        queue<TreeNode*> q;
        q.push(targetNode);
        
        
        while(!q.empty())
        {
            int s = q.size();
            bool flag = 0;
            
            for(int i=0;i<s;i++)
            {
                TreeNode* temp = q.front();
                q.pop();
                
                
                if(mp[temp] && !vis[mp[temp]])
                {
                    q.push(mp[temp]);
                    vis[mp[temp]] = 1;
                    flag = 1;
                }
                
                if(temp->left && !vis[temp->left]){
                    q.push(temp->left);
                    vis[temp->left] = 1;
                    flag = 1;
                }
                
                if(temp->right && !vis[temp->right]){
                    q.push(temp->right);
                    vis[temp->right] = 1;
                    flag = 1;
                }
                
        
                
            }
            if(flag)
                time++;
        }
        return time;
    }
    
    
    TreeNode* levelOrder(TreeNode* &root,map<TreeNode*,TreeNode*> &mp,int target)
    {
        if(root == nullptr)
            return nullptr;
        
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* res;
        while(!q.empty())
        {
            TreeNode* temp = q.front();
            q.pop();
            
            if(temp->val == target)
                res = temp;
            
            if(temp->left)
            {
                mp[temp->left] = temp;
                q.push(temp->left);
            }
            
            if(temp->right)
            {
                mp[temp->right] = temp;
                q.push(temp->right);
            }
            
        }
        return res;
    }
    int amountOfTime(TreeNode* root, int target) 
    {
        map<TreeNode*,TreeNode*> mp;
        TreeNode* targetNode = levelOrder(root,mp,target);
        return dobfs(mp,targetNode);
    }

};

```
