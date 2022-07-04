// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int>& array1, vector<int>& array2);


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
   
         
            
            
        double MedianOfArrays(vector<int>& a, vector<int>& b)
    {
    	// to make sure a is smaller of the arrays
        if(a.size()>b.size()) 
            return MedianOfArrays(b,a);
            
        int l=0, r =a.size();
        int siz = (a.size()+b.size()+1)>>1; // median location
        while(l<=r){
        // we try taking mid elements from A and rest from B
            int mid = (l+r)>>1;	
            int sizeb = siz-mid;
            int ra= mid ? a[mid-1] : INT_MIN;
            int la= mid+1<=a.size() ? a[mid] : INT_MAX;
            int rb = sizeb ? b[sizeb-1]:INT_MIN;
            int lb = sizeb+1<=b.size() ? b[sizeb]:INT_MAX;
            
            // if Perfect Partitioning return median
            if(ra<=lb && la>=rb){
                if((a.size()+b.size()) & 1)
                    return max(ra,rb);
                return (max(ra,rb)+min(la,lb))/2.0;
            }
            if(la<rb)
                l=mid+1;
            else
                r=mid-1;
        }
        return 0;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        cin>>n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i){
            cin>>array2[i];
        }
        Solution ob;
        cout<<ob.MedianOfArrays(array1, array2)<<endl;
    }
    return 0; 
}


  // } Driver Code Ends