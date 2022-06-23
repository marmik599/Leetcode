// { Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends
//User function Template for C++

class Solution {
public:
    


bool checkValid(int i, int j, int row, int col)
  {
      if(i<0 || j<0 || i>=row || j>=col)
      return false;
      
      return true;
  }
   int helpaterp(vector<vector<int>> grid)
   {
       //code here
       int row=grid.size();
      int col=grid[0].size();
      queue<pair<int,int>>q;
      int count=0;
      for(int i=0; i<grid.size(); i++)
      {
          for(int j=0; j<grid[0].size(); j++)
          {
              if(grid[i][j]==2)
              {
                  q.push({i,j});
              }
          }
      }
      while(q.empty()==false)
      {
          int size=q.size();
          bool flag=false;
          for(int k=0; k<size; k++)
          {
              int i=q.front().first;
              int j=q.front().second;
              q.pop();
              if(checkValid(i+1, j,row, col ) && grid[i+1][j]==1)
              {
                  grid[i+1][j]=2;
                  q.push({i+1,j});
                  flag=true;
              }
              if(checkValid(i-1, j, row, col) && grid[i-1][j]==1)
              {
                  grid[i-1][j]=2;
                  q.push({i-1,j});
                  flag=true;
              }
          
              if(checkValid(i,j+1,row,col) && grid[i][j+1]==1)
              {
                  grid[i][j+1]=2;
                  q.push({i,j+1});
                  flag=true;
              }
          
              if(checkValid(i,j-1,row,col) && grid[i][j-1]==1)
              {
                  grid[i][j-1]=2;
                  q.push({i,j-1});
                  flag=true;
              }
          }
          if(flag==true)
          count++;
      }
      
      for(int i=0; i<row; i++)
      {
          for(int j=0; j<col; j++)
          {
              if(grid[i][j]==1)
              return -1;
          }
      }
      
      return count;
   }
};


// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R;int C;
        
        cin>>R>>C;
        vector<vector<int>> hospital;
        int i,j;
        for(i=0;i<R;i++)
         {   vector<int> temp;
             for(j=0;j<C;j++)
            {
                int k;
                cin>>k;
                temp.push_back(k);
            }
            hospital.push_back(temp);
         }
        
        Solution ob;
        int ans = ob.helpaterp(hospital);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends