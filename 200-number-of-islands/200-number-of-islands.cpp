class Solution {
public:
    bool isValid(int i,int j,int m,int n,vector<vector<char>>& grid)
    {
        if(i>=0 && i<n && j>=0 && j<m && grid[i][j]=='1')
            return true;
        
        return false;
    }
    void solve(int i,int j,int m,int n,vector<vector<char>>& grid)
    {
        grid[i][j]='0';
        
        if(isValid(i-1,j,m,n,grid))
            solve(i-1,j,m,n,grid);
        
        if(isValid(i+1,j,m,n,grid))
            solve(i+1,j,m,n,grid);
        
        if(isValid(i,j-1,m,n,grid))
            solve(i,j-1,m,n,grid);
        
        if(isValid(i,j+1,m,n,grid))
            solve(i,j+1,m,n,grid);
        
    }
    int numIslands(vector<vector<char>>& grid)
    {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1')
                {
                    ans++;
                    solve(i,j,m,n,grid);  
                }
                    
            }
        }
        return ans;
    }
};