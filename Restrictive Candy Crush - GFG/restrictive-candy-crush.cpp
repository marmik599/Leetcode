// { Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    string Reduced_String(int k,string s)
    {
        stack<pair<char,int>> st;
        for(int i=0;i<s.length();i++)
        {
            if(st.empty() || st.top().first!=s[i])
            {
                st.push({s[i],1});
            }
            else if(st.top().first==s[i])
            {
                int x=st.top().second;
                st.pop();
                st.push({s[i],x+1});
            }
            if(st.top().second == k)
            {
                st.pop();
            }
        }
        string ans="";
        while(!st.empty())
        {
            int x=st.top().second;
            char c=st.top().first;
            st.pop();
            for(int i=0;i<x;i++)
            {
                ans+=c;
            }
            
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }


};

// { Driver Code Starts.

int main() {
    
    
    int t;cin>>t;
    while(t--)
    {
        int k;
        cin>>k;
        string s;
        cin>>s;
        Solution obj;
        cout<<obj.Reduced_String(k,s)<<"\n";
        
    }
    
	return 0;
}  // } Driver Code Ends