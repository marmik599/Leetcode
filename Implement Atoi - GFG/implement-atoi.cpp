// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string str) 
    {
        bool flag=false;
        int ans=0;
        int count;
        for(int i=0;i<str.length();i++)
        {
            count=str[i]-'0';
            if(str[i]=='-' && i==0)
                flag=true;
                
            else if(count>=0 && count<=9)
                ans=ans*10+count;
                
            else
                return -1;
        }
        if(flag==false)
            return ans;
        return -1*ans;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}  // } Driver Code Ends