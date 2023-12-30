
//Code Link - https://practice.geeksforgeeks.org/problems/topological-sort/1?

class Solution
{
    private:
        void dfs(int start,int vis[],stack<int> &st,vector<int> adj[])
        {
            vis[start]=1;
            
            for(auto it:adj[start])
            {
               if(!vis[it])
                dfs(it,vis,st,adj);
            }
            
            st.push(start);
        }
        
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    
	    int vis[V] = {0};
    	stack<int> st;
	    for(int i=0;i<V;i++)
	    {
	        if(!vis[i])
	        {
	            dfs(i,vis,st,adj);
	        }
	    }
	    
	    vector<int> result;
	    
	    while(!st.empty())
	    {
	        result.push_back(st.top());
	        st.pop();
	    }
	    
	    return result;
	}
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/

