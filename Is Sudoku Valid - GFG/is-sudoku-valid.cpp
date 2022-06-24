// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int isValid(vector<vector<int>> mat)
    {
       unordered_set<string> s;
       
       for(int i=0;i<9;i++)
       {
           for(int j=0;j<9;j++)
           {
               if(mat[i][j]==0)
                continue;
                
                int row=i;
                int col=j;
                int box=(row/3)*3 + col/3;
                
                string str="row" + to_string(row) + to_string(mat[i][j]);
                string stc="col" + to_string(col) + to_string(mat[i][j]);
                string stb="box" + to_string(box) + to_string(mat[i][j]);
                
                if(s.find(str)!=s.end() || s.find(stc)!=s.end() || s.find(stb)!=s.end())
                    return false;
                s.insert(str);
                s.insert(stc);
                s.insert(stb);

            }
       }
       return true;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        vector<vector<int>> mat(9, vector<int>(9, 0));
        for(int i = 0;i < 81;i++)
            cin>>mat[i/9][i%9];
        
        Solution ob;
        cout<<ob.isValid(mat)<<"\n";
    }
    return 0;
}  // } Driver Code Ends