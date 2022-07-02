// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the largest number after k swaps.
    void solve(string &str,int n,int k,string &ans,int a)
    {
        if(k==0)
            return;
            
        char maxi=str[a];
        for(int i=a+1;i<n;i++)
        {
            if(maxi<str[i])
                maxi=str[i];
        }
        if(maxi!=str[a])
        {
            k--;
        }
        for(int i=n-1;i>=a;i--)
        {
            if(str[i]==maxi)
            {
                swap(str[i],str[a]);
                if(ans<str)
                    ans=str;
                solve(str,n,k,ans,a+1);
                swap(str[i],str[a]);
            }
        }
    }
    string findMaximumNum(string str, int k)
    {
         string ans=str;
         int n=str.length();
        solve(str,n,k,ans,0);
        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}
  // } Driver Code Ends