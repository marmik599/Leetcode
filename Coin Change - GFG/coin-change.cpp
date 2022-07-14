// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    long long int f(int i, int value, int S[], vector<vector<long long>> &dp){
       if(value==0)
           return 1;
       if(i==0)
       {
           return value%S[i]==0;
       }
       
       if(dp[i][value]!=-1)
           return dp[i][value];
           
       long long inc = 0;
       if(value>=S[i]) inc = f(i,value-S[i],S,dp);
       long long exc  = f(i-1,value,S,dp);
       
       return dp[i][value] = inc + exc;
   }
   long long int count(int S[], int n, int m) {
       vector<vector<long long>> dp(n,vector<long long>(m+1,-1));
       return f(n-1,m,S,dp);
   }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int arr[m];
        for (int i = 0; i < m; i++) cin >> arr[i];
        Solution ob;
        cout << ob.count(arr, m, n) << endl;
    }

    return 0;
}  // } Driver Code Ends