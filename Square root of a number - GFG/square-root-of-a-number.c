// { Driver Code Starts
//Initial Template for C

#include<stdio.h>
  

 // } Driver Code Ends
//User function Template for C

long long int floorSqrt(long long int x) 
{
    long long int start=0;
    long long int end=x;
    long long int ans=-1;
    long long int mid;
    while(start<=end)
    {
         mid=start+(end-start)/2;
        long long int sq=mid*mid;
        if(sq==x)
        {
            return mid;
        }
        else if(sq>x)
        {
            end=mid-1;
            
        }
            
        else
            {
               
                start=mid+1;
            }
    }
    if(mid*mid>x)
        return mid-1;
    return mid;
}

// { Driver Code Starts.

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		long long n;
		scanf("%ld", &n);
	
		printf("%ld\n", floorSqrt(n));
	}
    return 0;   
}
  // } Driver Code Ends