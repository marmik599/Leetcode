// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  bool ispal(string s)
  {
      int start=0;
      int end=s.length()-1;
      
      while(start<=end)
      {
          if(s[start++]!=s[end--])
          {
              return false;
          }
      }
      return true;
  }
  void solve(vector<vector<string>> &ans,vector<string> &temp,string s)
  {
      if(s=="")
      {
          ans.push_back(temp);
          return;
      }
      for(int i=0;i<s.size();i++)
      {
          string left=s.substr(0,i+1);
          string right=s.substr(i+1);
          if(ispal(left))
          {
              temp.push_back(left);
              solve(ans,temp,right);
              temp.pop_back();
          }
      }
  }
    vector<vector<string>> allPalindromicPerms(string s) 
    {
        vector<vector<string>> ans;
        vector<string> temp;
        solve(ans,temp,s);
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        
        cin>>S;

        Solution ob;
        vector<vector<string>> ptr = ob.allPalindromicPerms(S);
        
        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                cout<<ptr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends