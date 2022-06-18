// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
    private:
    void dfs(vector<vector<int>> adj,vector<bool> &visited,int src,int V)
    {
        visited[src]=true;
        for(int i=0;i<V;i++)
        {
            if(visited[i]==false && adj[src][i]==1)
            {
                dfs(adj,visited,i,V);
            }
        }
    }
  public:
    int numProvinces(vector<vector<int>> adj, int V) 
    {
        vector<bool> visited(V,false);
        int count=0;
        for(int i=0;i<V;i++)
        {
            if(visited[i]==false)
            {
                dfs(adj,visited,i,V);
                count++;
            }
        }
        return count;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}  // } Driver Code Ends