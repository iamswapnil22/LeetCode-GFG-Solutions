//code link - https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1?

class Solution {
  private:
    void topologicalSort(int src,vector<int> &vis,
    vector<pair<int,int>> adj[],stack<int> &st)
    {
        vis[src]=1;
        
        for(auto it : adj[src])
        {
            int v = it.first;
            if(!vis[v])
            {
                topologicalSort(v,vis,adj,st);
            }
        }
        
        st.push(src);
    }
    
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector < pair < int, int >> adj[N];
        
        for(int i=0;i<M;i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v,wt});
        }
        
        vector<int> vis(N,0);
        stack<int> st;
        for(int i=0;i<N;i++)
        {
            if(!vis[i])
            {
                topologicalSort(i,vis,adj,st);
            }
        }
        
        
        vector<int> dis(N,1e9);
        dis[0]=0; // IMPORTANT LINE
        while(!st.empty())
        {
            int node = st.top();
            st.pop();
            for(auto it : adj[node])
            {
                //it.first == v
                //it.second == wt
                if(dis[node]+it.second <dis[it.first])
                {
                    dis[it.first]=dis[node]+it.second;
                }
            }
        }
        
        for(int i=0;i<N;i++)
        {
            if(dis[i]==1e9)
                dis[i]=-1;
                
        }
        return dis;
        
    }
    
    // THE Question is not that tough but there is multiple chacnces of getting stuck in silly mistake
};

// To find the shortest path in a directed acyclic graph, 
//there are two step.
// Step one first we are need to use stack and perform topological stored on given ages vertex.
// Then step two. Take the notes one by one of the stack and relax the edges by using 2nd array, which is distance array