// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to return Largest Number

class Solution
{
    public:
    //Function to return the largest possible number of n digits
    //with sum equal to given sum.
    string largestNumber(int n, int sum)
    {
       string ans="";
       while(n>0)
       {
           if(sum>=9)
           {
               ans=ans+'9';
               sum=sum-9;
               n--;
           }
           else if(sum>=0 && sum<9)
           {
               ans=ans+to_string(sum);
               sum=0;
               n--;
           }
       }
       if(sum>0)
        return "-1";
    
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin>>t;

	while(t--)
	{
	    //taking n and sum
		int n,sum;
		cin>>n>>sum;
		
        Solution obj;
        //function call
		cout<<obj.largestNumber(n, sum)<<endl;
	}
	return 0;
}  // } Driver Code Ends