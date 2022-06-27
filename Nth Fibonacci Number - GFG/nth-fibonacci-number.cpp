// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution {
  public:
   #define mod 1'000'000'007
  long long int fibo(long long int n,vector<long long int> &dp)
  {
      if(n==0 || n==1)
        return n;
        
        if(dp[n]!=-1)
            return dp[n];
            
        return dp[n]=(fibo(n-1,dp)%mod + fibo(n-2,dp)%mod)%mod;
  }
    long long int nthFibonacci(long long int n)
    {
        vector<long long int> dp(n+1);
        for(int i=0;i<n+1;i++)
        {
            dp[i]=-1;
        }
        return fibo(n,dp);
    }
    
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}
  // } Driver Code Ends