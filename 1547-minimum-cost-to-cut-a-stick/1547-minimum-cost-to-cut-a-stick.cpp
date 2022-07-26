class Solution {
public:
    // int solve(int i,int j,vector<int> cuts,vector<vector<int>> &dp)
    // {
    //     if(i>j)
    //         return 0;
    //     if(dp[i][j]!=-1)
    //         return dp[i][j];
    //     int mini=INT_MAX;
    //     for(int index=i;index<=j;index++)
    //     {
    //         int cost=cuts[j+1]-cuts[i-1]+solve(i,index-1,cuts,dp)+solve(index+1,j,cuts,dp);
    //         mini=min(mini,cost);
    //     }
    //     return dp[i][j]=mini;
    // }
    
    int minCost(int n, vector<int>& cuts)
    {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        int m=cuts.size();
        
        
        vector<vector<int>> dp(m,vector<int>(m,0));
        
        for(int i=m-2;i>=1;i--)
        {
            for(int j=1;j<=m-2;j++)
            {
                if(i>j)
                    continue;
                int mini=INT_MAX;
                for(int index=i;index<=j;index++)
                {
                    int cost=cuts[j+1]-cuts[i-1]+dp[i][index-1]+dp[index+1][j];
                    mini=min(mini,cost);
                }
                dp[i][j]=mini;
            }
        }
        return dp[1][m-2];
        //return solve(1,cuts.size()-2,cuts,dp);
    }
};