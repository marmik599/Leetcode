// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
bool solve(int arr[],int index,int sum,vector<vector<int>> &dp)
    {
        if(sum==0)
            return true;
            
        if(index==0)
        {
            if(arr[index]==sum)
                return true;
            else
                return false;
        }
        if(dp[index][sum]!=-1)
            return dp[index][sum];
        
        bool not_taken=solve(arr,index-1,sum,dp);
        bool taken=false;
        if(arr[index]<=sum)
            taken=solve(arr,index-1,sum-arr[index],dp);
            
        return dp[index][sum]=(taken||not_taken);
    }
    int equalPartition(int n, int arr[])
    {
       
        int target=0;
        for(int i=0;i<n;i++)
        {
            target+=arr[i];
        }
        if(target%2 == 1)
            return false;
        vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
        
        return solve(arr,n-1,target/2,dp);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends