// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    vector<int> increment(vector<int> arr ,int n) {
       vector<int> ans;
       int sum=0;
       int carry=0;
       int i=n-1;
       
       
       sum=sum+arr[i]+1;
       carry=sum/10;
       sum=sum%10;
       ans.push_back(sum);
        i--;
       while(i>=0)
       {
           sum=arr[i]+carry;
           carry=sum/10;
           sum=sum%10;
           
           ans.push_back(sum);
           i--;
       }
       if(carry!=0)
        ans.push_back(carry);
        
       int start=0;
       int end=ans.size()-1;
       while(start<end)
       {
           swap(ans[start],ans[end]);
           start++;
           end--;
       }
       return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        char c;
        
        cin>>N;
        vector<int> arr(N);
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        vector<int> res = ob.increment(arr,N);
        for(int i: res)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends