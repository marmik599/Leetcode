class Solution {
public:
 vector<bool>visited, recst;
    void addEdge(vector<int> adj[], int src, int des){
        adj[src].push_back(des);
    }
    bool dfs(vector<int> adj[], int s){
        visited[s]= true;
        recst[s]= true;
        for(auto u: adj[s]){
            if(visited[u]==false and dfs(adj, u)) return true;
            else if(recst[u]) return true;
        }
        recst[s]= false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n= numCourses, m= prerequisites.size();
        vector<int> adj[n];
        for(int i=0; i<m; i++)
            addEdge(adj, prerequisites[i][0], prerequisites[i][1]);
        visited.resize(n, false);
        recst.resize(n, false);
        for(int i=0; i<n; i++)
            if(visited[i]==false)
                if(dfs(adj, i)) return false;
        return true;
    }
};