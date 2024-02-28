# [513. Find Bottom Left Tree Value](https://leetcode.com/problems/find-bottom-left-tree-value/description/?envType=daily-question&envId=2024-02-28)

```
class Solution {
    public int findBottomLeftValue(TreeNode root) {
        if(root == null)
            return 0;
        Queue<TreeNode> q=new LinkedList<>();
        q.add(root);
        ArrayList<Integer> arr = new  ArrayList<Integer>();

        while(!q.isEmpty())
        {
            TreeNode temp = q.peek();
            q.remove();

            arr.add(temp.val);
            if(temp.right != null)
                q.add(temp.right);
            if(temp.left != null)
                q.add(temp.left);
            

        }
        return arr.get(arr.size()-1);

    }
}
```
