//code link - https://practice.geeksforgeeks.org/problems/bipartite-graph/1?

/*
if a graph has a cycle of odd lenght edges then this can't be a bipartite graph 
and we use 0/1 to color graph with color array intially -1;
*/


class Solution {
private:
    bool dfs(int node,int col,vector<int> &color,vector<int> adj[])
    {
        color[node]=col;
        
        for(auto it:adj[node])
        {
            if(color[it]==-1)
            {
                if(dfs(it,!col,color,adj)==false) return false;
            }
            else if(color[it]==col) return false;
        }
        return true;
    }
public:
	bool isBipartite(int V, vector<int>adj[]){
	    vector<int> color(V,-1);
	    
	    for(int i=0;i<V;i++)
	    {
            if(color[i]==-1)
            {
               if(dfs(i,0,color,adj) == false) return false;
            }
	    }
	    return true;
	}

};