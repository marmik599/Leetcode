// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    bool bfscycle(int source,vector<bool> &visited,vector<int> adj[])
    {
         
        unordered_map<int,int> parent;
        
        queue<int> q;
        
        visited[source]=true;
        q.push(source);
        parent[source]=-1;
        
        while(q.size()>0)
        {
            int u=q.front();
            q.pop();
            
            for(auto i:adj[u])
            {
                if(visited[i]==true && i!=parent[u])
                    return true;
                    
             else if(visited[i]==false)
                {
                    q.push(i);
                    visited[i]=true;
                    parent[i]=u;
                }
                
                    
            }
            
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[])
    {
        vector<bool> visited(V,false);
       for(int i=0;i<V;i++)
       {
           if(visited[i]==false)
           {
               bool ans=bfscycle(i,visited,adj);
               if(ans==true)
                return true;
           }
       }
       return false;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends