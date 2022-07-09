// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // num: size of array
    //Function to find maximum circular subarray sum.
    int circularSubarraySum(int arr[], int num)
    {
        
        int maxsum=INT_MIN;
        int minsum=INT_MAX;
        int sum=0;
        
        int tmaxsum=0;
        int tminsum=0;
        
        for(int i=0;i<num;i++)
        {
            sum+=arr[i];
            tmaxsum+=arr[i];
            maxsum=max(tmaxsum,maxsum);
            if(tmaxsum<0)
                tmaxsum=0;
                
            tminsum+=arr[i];
            minsum=min(tminsum,minsum);
            if(tminsum>0)
                tminsum=0;
        }
        if(sum==minsum)
            return maxsum;
            
        return max(maxsum,sum-minsum);
    
    }
};

// { Driver Code Starts.

int main()
 {
	int T;
	
	//testcases
	cin>> T;
	
	while (T--)
	{
	    int num;
	    
	    //size of array
	    cin>>num;
	    int arr[num];
	    
	    //inserting elements
	    for(int i = 0; i<num; i++)
	        cin>>arr[i];
	        
	    Solution ob;
	    //calling function
	    cout << ob.circularSubarraySum(arr, num) << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends