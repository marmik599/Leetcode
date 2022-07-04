// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    bool isposs(int a[], int n, int m,int mid)
    {
        int cstud=1;
        int pagesum=0;
        for(int i=0;i<n;i++)
        {
            if(pagesum+a[i]<=mid)
            {
                
                pagesum+=a[i];
            }
            else
            {
                cstud++;
                if(cstud>m || a[i]>mid)
                    return false;
                pagesum=a[i];    
            }
            
        }
        return true;
    }
    int findPages(int a[], int n, int m) 
    {
       int start=0;
       int sum=0;
       for(int i=0;i<n;i++)
        sum+=a[i];
        
        int end=sum;
        int ans=-1;
        
        int mid=start+(end-start)/2;
        
        while(start<=end)
        {
            if(isposs(a,n,m,mid))
            {
                ans=mid;
                end=mid-1;
            }
            else
            {
                start=mid+1;
            }
            mid=start+(end-start)/2;
        }
        return ans;
    
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends