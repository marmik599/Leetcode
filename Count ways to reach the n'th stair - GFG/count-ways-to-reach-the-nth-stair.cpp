// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to count number of ways to reach the 
    int const M=1000000007;
    int count(int n,vector<int> &dp)
    {
        if(n==0)
            return 1;
        if(n<0)
            return 0;
            
            if(dp[n]!=-1)
                return dp[n];
            
        return dp[n]=(count(n-1,dp)+count(n-2,dp))%M;
    }
    int countWays(int n)
    {
       vector<int> dp(n+1);
       for(int i=0;i<n+1;i++)
       {
           dp[i]=-1;
       }
       return count(n,dp);
    }
};



// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}
  // } Driver Code Ends