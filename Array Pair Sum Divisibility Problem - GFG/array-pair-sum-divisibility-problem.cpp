// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> nums, int k) 
    {
        int n=nums.size();
        if(n%2==1)
            return false;

        unordered_map<int,int> mp;
        
        for(int i=0;i<n;i++)
        {
            mp[nums[i]%k]++;
        }
        if(mp[0]%2==1)
            return false;
            
        for(auto x:mp)
        {
            if(x.first!=0 && mp[x.first]!=mp[k-x.first])
                return false;
        }
        return true;
        
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}  // } Driver Code Ends