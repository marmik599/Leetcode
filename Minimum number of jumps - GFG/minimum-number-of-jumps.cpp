// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    // int solve(int index,int n,int arr[],vector<int> &dp)
    // {
    //     if(index>=n-1)
    //         return 0;
        
    //     int mini=INT_MAX-5;
        
    //     if(dp[index]!=-1)
    //         return dp[index];
    //     for(int i=1;i<=arr[index];i++)
    //     {
    //         mini=min(mini,solve(index+i,n,arr,dp)+1);
    //     }
    //     return dp[index]=mini;
    // }
    int minJumps(int arr[], int n)
    {
        // int mini=INT_MAX;
        // int dp[n];
        
        // int ans =solve(0,n,arr,dp);
        
        // if(ans>=INT_MAX-5)
        // {
        //     return -1;
        // }
        // return ans;
        if(n==1)
            return 0;
            
        if(arr[0]==0)
            return -1;
        int reach=arr[0];
        int step=arr[0];
        int jump=1;
        
        for(int i=1;i<n;i++)
        {
            if(i==n-1)
                return jump;
                
            reach=max(reach,i+arr[i]);
            step--;
            if(step==0)
            {
                jump++;
                if(reach<=i)
                    return -1;
                step=reach-i;
            }
        }
        return -1;
 
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends