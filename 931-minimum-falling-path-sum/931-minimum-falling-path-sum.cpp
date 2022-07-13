class Solution {
public:
    int solve(int i,int j,int n,vector<vector<int>> &matrix,vector<vector<int>> &dp)
    {
    if( j>=n || j<0)
            return 1e9;
            
        if(i==n-1)
        {
            return matrix[i][j];
        }
         
         if(dp[i][j]!=-1)
            return dp[i][j];
            
        int down=matrix[i][j]+solve(i+1,j,n,matrix,dp);
        int leftdiag=matrix[i][j]+solve(i+1,j-1,n,matrix,dp);
        int diag=matrix[i][j]+solve(i+1,j+1,n,matrix,dp);
            
        int ans=min(min(down,leftdiag),diag);
        return dp[i][j]=ans;
    }
        
    int minFallingPathSum(vector<vector<int>>& matrix) 
    {
         int ans=INT_MAX;
        int n=matrix.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        for(int i=0;i<n;i++)
        {
          int posans=solve(0,i,n,matrix,dp);
          ans=min(posans,ans);
        }
        return ans;    
    }
};