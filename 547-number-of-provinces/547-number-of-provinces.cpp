class Solution {
public:
    void dfs(vector<vector<int>>& isConnected,vector<bool>&visited,int s,int n){
        visited[s]=true;
        for(int i=0;i<n;i++){
            if(visited[i]==false && isConnected[s][i]==1){ // checking both condition not visited and connected
                dfs(isConnected,visited,i,n);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        int ans=0;
        vector<bool>visited(n,false);
        for(int i=0;i<n;i++){
            if(visited[i]==false){
                ans++;
                dfs(isConnected,visited,i,n);
            }
        }
        return ans;
    }
};