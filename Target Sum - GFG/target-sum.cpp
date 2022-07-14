// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
  int solve(int index,vector<int> a,int tar,vector<vector<int>> &dp)
  {
      if(index == 0){
            if(tar==0 && a[0]==0)
                return 2;
            if(tar==0 || tar == a[0])
                return 1;
            return 0;
    }
    if(dp[index][tar]!=-1)
        return dp[index][tar];
    int not_taken=solve(index-1,a,tar,dp);
    int taken=0;
    if(tar>=a[index])
        taken=solve(index-1,a,tar-a[index],dp);
        
    return dp[index][tar]=taken+not_taken;
  }
    int findTargetSumWays(vector<int>&a ,int target) 
    {
            int n=a.size();
            int totalsum=0;
            for(int i=0;i<n;i++)
            {
                totalsum+=a[i];
            }
            if((totalsum - target)<0) return 0;
            if((totalsum-target)%2 == 1) return 0;
            int tar= (totalsum-target)/2;
            vector<vector<int>> dp(n,vector<int> (tar+1,-1));
            return solve(n-1,a,tar,dp);
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>arr(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>arr[i];
        }
        int target;
        cin >> target;

        Solution ob;
        cout<<ob.findTargetSumWays(arr,target);
        cout<<"\n";
    }
    return 0;
}  // } Driver Code Ends