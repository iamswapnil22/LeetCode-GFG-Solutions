/*This is a Backtracking problem in which we need to go from (0,0)  to (n-1,n-1) position 
and return all the path contains up down left right direction in sorted order we must use visited array 
rather than making changes in original data*/

//NEED TO SOLVE THIS PROBLEM AGAIN FOR SURE :)

class Solution{
    public:
    int dr[4]={-1,+1,0,0};
    int dc[4]={0,0,-1,+1};
    vector<char> dir{'U','D','L','R'};
    bool isValid(int r ,int c,int n,vector<vector<int>> &vis,vector<vector<int>> &m){
        if(r>=0 && c>=0 && r<n && c<n && vis[r][c]==0 && m[r][c]==1)return true;
        else return false;
    }
    void solve(int row,int col,vector<string>&result,string ans,vector<vector<int>> &m,vector<vector<int>> &vis){
        int n=m.size();
        if(row==n-1 && col==n-1){
            result.push_back(ans);
            return;
        }
        for(int i=0;i<4;i++){
            int nr=row+dr[i];
            int nc=col+dc[i];
            if(isValid(nr,nc,n,vis,m)){
                vis[nr][nc]=1;//not visiting 0,0;
                solve(nr,nc,result,ans+dir[i],m,vis);
                vis[nr][nc]=0;
            }
        }
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<vector<int>>vis(n,vector<int>(n,0));
        string ans="";
        vector<string>result;
        if(m[0][0]==0)return result;
          vis[0][0] = 1;
        solve(0,0,result,ans,m,vis);
        return result;
        // Your code goes here
    }
};
