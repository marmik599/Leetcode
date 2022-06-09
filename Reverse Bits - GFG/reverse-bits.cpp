// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    unsigned int reverseBits(unsigned int n)
    {
        unsigned int ans=0;
        while(n)
        {
            if(n & 1)
                ans++;
            n>>=1;
            ans<<=1;
        }
        ans>>=1;
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        
        Solution ob;
        cout<< ob.reverseBits(N) <<"\n";
        
    }
    return 0;
}
  // } Driver Code Ends