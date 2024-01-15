//Code Link - https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        vector<int> dis(V,INT_MAX);
        
      //  for(int i=0;i<V;i++)    dis[i]=1e9;
        
        dis[S] = 0;
        
        pq.push({0,S});
        
        while(!pq.empty())
        {
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto it:adj[node])
            {
                int adjNode = it[0];
                int edgeW = it[1];
                
                
                if(dist+edgeW < dis[adjNode])
                {
                    dis[adjNode] = dist+edgeW;
                    pq.push({dist+edgeW,adjNode});
                }
            }
            
        }
        return dis;
        
    }
};
