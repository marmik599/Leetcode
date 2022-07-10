// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
    int solve(vector<int> &dp,vector<int> cost,int n)
    {
        if(n==0 || n==1)
            return cost[n];
            
            if(dp[n]!=-1)
                return dp[n];
            
        return dp[n]=cost[n]+min(solve(dp,cost,n-1),solve(dp,cost,n-2));
            
    }
    int minCostClimbingStairs(vector<int>&cost ,int n) 
    {
        vector<int> dp(n+1,-1);
        return min(solve(dp,cost,n-1),solve(dp,cost,n-2));
    }
    
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>cost(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>cost[i];
        }

        Solution ob;
        cout<<ob.minCostClimbingStairs(cost,N);
        cout<<"\n";
    }
    return 0;
}  // } Driver Code Ends