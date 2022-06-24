// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    //Function to find if there exists a triplet in the 
    //array A[] which sums up to X.
    bool find3Numbers(int A[], int n, int X)
    {
        unordered_set<int> s;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int sum=A[i]+A[j];
                if(s.find(X-sum)!=s.end())
                    return true;
                    
                s.insert(A[i]);
            }
        }
        return false;
    }

};

// { Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,X;
		cin>>n>>X;
		int i,A[n];
		for(i=0;i<n;i++)
			cin>>A[i];
		Solution ob;
        cout <<  ob.find3Numbers(A, n, X) << endl;
    }
}
  // } Driver Code Ends