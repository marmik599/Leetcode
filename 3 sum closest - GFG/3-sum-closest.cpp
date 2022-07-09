// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int closest3Sum(int a[], int n, int x)
    {
       sort(a,a+n);
       int ans=a[0]+a[1]+a[2];
       for(int i=0;i<=n-3;i++)
       {
           int b=i+1;
           int c=n-1;
           while(b<c)
           {
               int temp=a[i]+a[b]+a[c];
               if(temp==x)
                return x;
                
                if(abs(x-temp)<abs(x-ans))
                ans=temp;
                
                if(temp<x)
                b++;
                
                else
                c--;
           }
       }
       return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int Arr[N];
        for(int i=0;i<N;i++)    
            cin>>Arr[i];
        int X;
        cin>>X;
        Solution obj;
        cout<<obj.closest3Sum(Arr, N, X)<<endl;
    }
    return 0;
}  // } Driver Code Ends