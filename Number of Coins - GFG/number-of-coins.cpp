// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	 int solve1(int coins[],int amount,int m)
    {
        vector<int> dp(amount+1,INT_MAX);
        dp[0]=0;
        
        for(int i=0;i<=amount;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i-coins[j]>=0 && dp[i-coins[j]]!=INT_MAX)
                    dp[i]=min(dp[i],1+dp[i-coins[j]]);
            }
        }
          return dp[amount];  
    } 
	int minCoins(int coins[], int m, int amount) 
	{ 
	    int n=amount;
        vector<int> dp(n+1,-1);
        int ann= solve1(coins,amount,m);
        if(ann==INT_MAX)
            return -1;
        return ann;
	    
	} 
	  
};

// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends