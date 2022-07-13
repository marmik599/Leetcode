// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int func(int i, int j,vector<vector<int>> &Matrix, vector<vector<int>> &dp
, int N){
   if(j<0 || j>=N)return 0;
   if(i==N-1){
       return Matrix[i][j];
   }
   if(dp[i][j]!=-1)return dp[i][j];
   int a=Matrix[i][j]+func(i+1,j-1,Matrix,dp,N);
   int b=Matrix[i][j]+func(i+1,j,Matrix,dp,N);
   int c=Matrix[i][j]+func(i+1,j+1,Matrix,dp,N);
   return dp[i][j]=max({a,b,c});
}
   int maximumPath(int N, vector<vector<int>> Matrix)
   {
       // code here
      
       vector<vector<int>> dp(N,vector<int>(N,-1));
       int ans=INT_MIN;
       for(int i=0; i<N; i++){
          int posans=func(0,i,Matrix,dp,N);
          ans=max(ans,posans);
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