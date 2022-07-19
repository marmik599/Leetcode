class Solution {
public:
    int solve(int index,int buy,int trans,vector<int> &prices,vector<vector<vector<int>>> &dp)
    {
        if(index==prices.size() || trans==0)
            return 0;
        
        if(dp[index][buy][trans]!=-1)
            return dp[index][buy][trans];
        int profit=0;
        if(buy)
            profit=max(-prices[index]+solve(index+1,0,trans,prices,dp),solve(index+1,1,trans,prices,dp));
        else
            profit=max(prices[index]+solve(index+1,1,trans-1,prices,dp),solve(index+1,0,trans,prices,dp));
        
        return dp[index][buy][trans]=profit;
    }
    int maxProfit(int k,vector<int>& prices)
    {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>> (2,vector<int>(k+1,-1)));
        return solve(0,1,k,prices,dp);    
    }
};