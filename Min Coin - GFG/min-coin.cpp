// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int solve(int index,vector<int> nums,int amount,vector<vector<int>> &dp)
	{
	    if(index==0)
	    {
	        if(amount%nums[0]==0)
	            return amount/nums[0];
	            
	       return 1e9;
	    }
	    if(dp[index][amount]!=-1)
	        return dp[index][amount];
	    
	    int not_taken=0+solve(index-1,nums,amount,dp);
	    int taken=INT_MAX;
	    if(nums[index]<=amount)
	        taken=1+solve(index,nums,amount-nums[index],dp);
	        
	   return dp[index][amount]=min(taken,not_taken);
	}
	int MinCoin(vector<int>nums, int amount)
	{
	    int n=nums.size();
	    vector<vector<int>> dp(n,vector<int>(amount+1,-1));
	   int ans= solve(n-1,nums,amount,dp);
	   if(ans>=1e9)
	    return -1;
	    return ans;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, amount;
		cin >> n >> amount;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.MinCoin(nums, amount);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends