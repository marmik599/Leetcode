class Solution {
public:
    int solve(int r,int c,int m,int n,vector<vector<int>> &dp)
    {
        if(r==m-1 && c==n-1)
            return 1;
        
        if(r>=m || c>=n)
            return 0;
        if(dp[r][c]!=-1)
            return dp[r][c];
        
        int right=solve(r,c+1,m,n,dp);
        int left=solve(r+1,c,m,n,dp);
        
        return dp[r][c]=left+right;
    }
    int uniquePaths(int m, int n) 
    {
            vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
            return solve(0,0,m,n,dp);    
    }
};