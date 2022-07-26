class Solution {
public:
    // int solve(int i,int j,vector<int> nums,vector<vector<int>> &dp)
    // {
    //     if(i>j)
    //         return 0;
    //     int maxi=INT_MIN;
    //     if(dp[i][j]!=-1)
    //         return dp[i][j];
    //     for(int index=i;index<=j;index++)
    //     {
    //         int coins=nums[i-1]*nums[index]*nums[j+1] + solve(i,index-1,nums,dp)+solve(index+1,j,nums,dp);
    //         maxi=max(coins,maxi);
    //     }
    //     return dp[i][j]=maxi;
    // }
    int maxCoins(vector<int>& nums)
    {
        int n=nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        vector<vector<int>> dp (n+2,vector<int> (n+2,0));
        //return solve(1,n,nums,dp);
        
        for(int i=n;i>=1;i--)
        {
            for(int j=1;j<=n;j++)
            {
                if(i>j)
                    continue;
                int maxi=INT_MIN;
                for(int index=i;index<=j;index++)
                {
                    int cost=nums[i-1]*nums[index]*nums[j+1] + dp[i][index-1]+dp[index+1][j];
                    maxi=max(cost,maxi);
                }
                dp[i][j]=maxi;
            }
        }
        return dp[1][n];
    }
};