// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	int FindWays(int n, int m, vector<vector<int>>blocked_cells){
	    // Code here
	    long long int x=1e9+7;
	    vector<vector<int>>dp(n+1,vector<int> (m+1,-1));
	    
	    vector<vector<int>> mat(n+1,vector<int>(m+1,0));
	    for(auto i:blocked_cells)
	    {
	        mat[i[0]][i[1]]=-1;
	    }
	    return fun(n,m,mat,x,dp);
	    
	    
	}
	int fun(int n,int m,vector<vector<int>> &mat,long long int x,vector<vector<int>> &dp)
	{
	    if(n>=1 && m>=1 && mat[n][m]==-1)
	    return 0;
	    if(n==1 && m==1)
	    return 1;
	    if(n<1 || m<1)
	    return 0;
	    if(dp[n][m]!=-1)
	    return dp[n][m];
	    int up=fun(n-1,m,mat,x,dp)%x;
	    int left=fun(n,m-1,mat,x,dp)%x;
	  return dp[n][m]=(up+left)%x;
	}
	
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m, k;
		cin >> n >> m >> k;
		vector<vector<int>>blocked_cells;
		for(int i = 0; i < k; i++){
			int x, y;
			cin >> x >> y;
			blocked_cells.push_back({x, y});
		}
		Solution obj;
		int ans = obj.FindWays(n, m, blocked_cells);
		cout << ans <<'\n';
	}
	return 0;
}  // } Driver Code Ends