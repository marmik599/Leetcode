// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++


class Solution{
public:
    vector<long long> factorial(vector<long long> a, int n) 
    {
        long long maxi=INT_MIN;
        for(int i=0;i<n;i++)
        {
            maxi=max(maxi,a[i]);
        }
        vector<long long> fmax(maxi+1,-1);
        fmax[0]=1;
        fmax[1]=1;
        for(int i=2;i<maxi+1;i++)
        {
            fmax[i]=(i*fmax[i-1])%1000000007;
        }
        vector<long long> ans;
        for(int i=0;i<n;i++)
        {
            ans.push_back(fmax[a[i]]);
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<long long> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<long long> res = ob.factorial(a, n);
        for (i = 0; i < n; i++) {
            cout << res[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends