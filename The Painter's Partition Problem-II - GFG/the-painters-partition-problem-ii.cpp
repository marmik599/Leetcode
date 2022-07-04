// { Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution
{
  public:
   bool isposs(int a[], int n, int m,long long mid)
    {
        int cstud=1;
        long long  pagesum=0;
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
    long long minTime(int a[], int n, int m)
    {
        long long  start=0;
       long long  sum=0;
       for(long long  i=0;i<n;i++)
        sum+=a[i];
        
        long end=sum;
        long ans=-1;
        
        long mid=start+(end-start)/2;
        
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

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}  // } Driver Code Ends