//code link - https://www.geeksforgeeks.org/problems/number-of-enclaves/1?

class Solution {
  private:
    void dfs(int row,int col,vector<vector<int>> &vis,vector<vector<int>> &grid)
    {
        vis[row][col] = 1;
        int n = grid.size();
        int m = grid[0].size();
        
        int delrow[4] = {1,0,-1,0};
        int delcol[4] = {0,-1,0,1};
        
        for(int i=0;i<4;i++)
        {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            
            if(nrow>= 0 && nrow < n && ncol >= 0 && ncol < m 
            && !vis[nrow][ncol] && grid[nrow][ncol]==1)
            {
                dfs(nrow,ncol,vis,grid);
            }
            
            
        }
        
        
    }
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n,vector<int> (m,0));
        
        
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if((i==0 || j==0 || i == n-1 || j == m-1) && grid[i][j]==1)
                {
                    dfs(i,j,vis,grid);
                }
            }
        }
        
        int cnt = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(vis[i][j] == 0 && grid[i][j]==1)
                {
                    cnt++;
                }
                // cout<<vis[i][j]<<"\t";
            }
            
        }
        return cnt;
        
    }
};


/*
    0  1  1  0

    0  0  1  0

    0  0  1  0

    0  0  0  0

    it comes out of boundry 

    0  1  0  0

    0  0  1  0

    0  1  1  0

    0  0  0  0

    here three 1 are isolated and don;t touch any boundry guy or boundry itself

    *important condition 
    if((i==0 || j==0 || i == n-1 || j == m-1) && grid[i][j]==1){}

*/