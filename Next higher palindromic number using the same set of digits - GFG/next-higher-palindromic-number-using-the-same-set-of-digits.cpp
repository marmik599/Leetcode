// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
  string nexthigh(string ans)
  {
      int n=ans.length();
      int ind1;
      int ind2;
      //finding break point 1 which is finding the end of ascending part of the number
      for(ind1=n-2;ind1>=0;ind1--)
      {
          if(ans[ind1]<ans[ind1+1])
            break;
      }
      if(ind1<0)
      {
         reverse(ans.begin(),ans.end());
         return ans;
      }
      else
      {
            for(ind2=n-1;ind2>ind1;ind2--)
            {
                if(ans[ind2]>ans[ind1])
                break;
            }
      swap(ans[ind2],ans[ind1]);
      reverse(ans.begin()+ind1+1,ans.end());
      }
      
      return ans;
        
  }
  
    string nextPalin(string s) 
    { 
            int n=s.size();
            string ans="";
            for(int i=0;i<n/2;i++)
            {
                ans+=s[i];
            }
            ans=nexthigh(ans);
            string temp=ans;
            reverse(temp.begin(),temp.end());
            if(n%2==1)
                ans+=s[n/2];
                
            ans+=temp;
            if(ans>s)
                return ans;
            return "-1";
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution obj;
        cout << obj.nextPalin(s) << endl;
    }
    return 0;
}  // } Driver Code Ends