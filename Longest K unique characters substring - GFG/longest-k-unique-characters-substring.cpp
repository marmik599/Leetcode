// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) 
    {
        int ans=-1;
        unordered_map<char,int> mp;
        int i=0;
        int j=0;
        while(i<s.size())
        {
            if(mp.size()<=k)
            {
                mp[s[i]]++;
                i++;
            }
            if(mp.size()==k)
            {
                ans=max(ans,i-j);
            }
            if(mp.size()>k)
            {
                mp[s[j]]--;
                if(mp[s[j]]==0)
                    mp.erase(s[j]);
                j++;
            }
            
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}
  // } Driver Code Ends