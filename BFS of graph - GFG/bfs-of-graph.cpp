// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) 
    {
        bool visited[V];
        vector<int> ans;
        
        for(int i=0;i<V;i++)
            visited[i]=false;
            
        queue<int> q;
        int s=0;
        visited[s]=true;
        q.push(s);
        while(q.size()>0)
        {
            int u=q.front();
            q.pop();
            
            ans.push_back(u);
            
            for(int i:adj[u])
            {
                if(visited[i]==false)
                {
                    visited[i]=true;
                    q.push(i);
                }
            }
            
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends