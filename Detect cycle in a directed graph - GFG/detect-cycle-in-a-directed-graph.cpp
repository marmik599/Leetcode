// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    
    bool solve(int source,vector<int> adj[],vector<bool> &visited,vector<bool> &dfs_visited)
    {
        visited[source]=true;
        dfs_visited[source]=true;
        for(auto x:adj[source])
        {
            if(!visited[x])
            {
                bool cycle=solve(x,adj,visited,dfs_visited);
                if(cycle)
                    return true;
            }
            else if(dfs_visited[x]==true)
            {
                return true;
            }
           
        }
        dfs_visited[source]=false;
        return false;
    }
    bool isCyclic(int v, vector<int> adj[])
    {
        vector<bool> visited(v,false);
        vector<bool> dfs_visited(v,false);
        for(int i=0;i<v;i++)
        {
            if(!visited[i])
            {
                bool cycle=solve(i,adj,visited,dfs_visited);
                if(cycle)
                    return true;
            }
        }
        return false;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends