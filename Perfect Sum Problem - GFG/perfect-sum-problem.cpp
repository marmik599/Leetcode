// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int m=1e9+7;
	int perfect(int arr[],int n,int sum,vector<vector<int>>&dp){
   if(n==0){
       // if(sum==arr[0])return 1;
        if(sum==0&&arr[0]==0)return 2;
        if(sum==0||arr[0]==sum)return 1;
        return 0;
    }
  
    
    if(dp[n][sum]!=-1)return dp[n][sum];
    
    if(sum>=arr[n])return dp[n][sum] = (perfect(arr,n-1,sum-arr[n],dp)%m+perfect(arr,n-1,sum,dp)%m)%m;
    else return dp[n][sum] = perfect(arr,n-1,sum,dp)%m;
    
}
	int perfectSum(int arr[], int n, int sum)
	{
	    vector<vector<int>> dp(n+1,vector<int>(sum+1,-1));
        int ans=perfect(arr,n-1,sum,dp);
        return ans;
	
	}  
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends