class Solution {
public:
    int solve(int row,int col,vector<vector<int>> obstacleGrid,int m,int n,vector<vector<int>>& dp)
    {
         if(row>=m || col>=n)
        {
            return 0;
        }
        if(obstacleGrid[row][col]==1)
            return 0;
        if(row==m-1 && col==n-1)
        {
            return 1;
        }
        
        
        if(dp[row][col]!=-1)
            return dp[row][col];
        
        int right=solve(row,col+1,obstacleGrid,m,n,dp);
        int bottom=solve(row+1,col,obstacleGrid,m,n,dp);
        return dp[row][col]=bottom+right;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return solve(0,0,obstacleGrid,m,n,dp);
    }
};