// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int index,int w,int val[],int wt[],vector<vector<int>> &dp)
    {
        if(index==0)
        {
            return (int)((w/wt[0])*val[0]);
        }
        if(dp[index][w]!=-1)
            return dp[index][w];
        int not_taken=solve(index-1,w,val,wt,dp);
        int taken=INT_MIN;
        if(wt[index]<=w)
            taken=val[index]+solve(index,w-wt[index],val,wt,dp);
            
        return dp[index][w]=max(taken,not_taken);
    }
    int knapSack(int n, int w, int val[], int wt[])
    {
        vector<vector<int>> dp(n,vector<int>(w+1,-1));
       return solve(n-1,w,val,wt,dp);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}  // } Driver Code Ends