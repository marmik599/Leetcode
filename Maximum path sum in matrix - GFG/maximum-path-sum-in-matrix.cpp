// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int i,int j,int n,vector<vector<int>> &matrix,vector<vector<int>> &dp)
    {
       
        if( j>=n || j<0)
            return 0;
            
        if(i==n-1)
        {
            return matrix[i][j];
        }
         
         if(dp[i][j]!=-1)
            return dp[i][j];
            
        int down=matrix[i][j]+solve(i+1,j,n,matrix,dp);
        int leftdiag=matrix[i][j]+solve(i+1,j-1,n,matrix,dp);
        int diag=matrix[i][j]+solve(i+1,j+1,n,matrix,dp);
            
        int ans=max(max(down,leftdiag),diag);
        return dp[i][j]=ans;
        
    }
    int maximumPath(int n, vector<vector<int>> matrix)
    {
        int ans=INT_MIN;
        vector<vector<int>> dp(n,vector<int>(n,-1));
        for(int i=0;i<n;i++)
        {
           int posans=solve(0,i,n,matrix,dp);
           ans=max(posans,ans);
        }
        return ans;
    
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}  // } Driver Code Ends