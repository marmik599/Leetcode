// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countTriplets(int arr[], int n, int L, int R) 
    {
        if(n<3)
            return 0;
       sort(arr,arr+n);
       return solve(arr,n,R)-solve(arr,n,L-1);
        
    }
    int solve(int arr[],int n,int tar)
    {
      
        int ans=0;
        for(int right=n-1;right>=2;right--)
        {
            int left=0;
            int mid=right-1;
            while(left<mid)
            {
                if(arr[left]+arr[mid]+arr[right]<=tar)
                {
                    ans+=mid-left;
                    left++;
                }
                else
                    mid--;
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
        int N;
        cin >> N;
        int Arr[N];
        for (int i = 0; i < N; i++) cin >> Arr[i];
        int L, R;
        cin >> L >> R;
        Solution obj;
        cout << obj.countTriplets(Arr, N, L, R) << endl;
    }
    return 0;
}  // } Driver Code Ends