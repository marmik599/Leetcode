// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  int ispossible(int a[],int i,int n)
  {
      if(i==n-1)
        return 1;
        
        if(i<n-1 && a[i]==0)
            return 0;
            
        
        
        for(int j=1;j<=a[i];j++)
        {
            if(ispossible(a,i+j,n)==1)
                return 1;
        }
        return 0;
      
  }
    int canReach(int a[], int n) 
    {
         int i=0;
        
         return ispossible(a,i,n);
         
         
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.canReach(A,N) << endl;
    }
    return 0;
}  // } Driver Code Ends