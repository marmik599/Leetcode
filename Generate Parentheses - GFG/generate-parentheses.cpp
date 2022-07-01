// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


 // } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
   public:
    void solve(int n,vector<string>&ans,string temp,int i,int cnt1,int cnt0){
        if(i==n){
            ans.push_back(temp);
            return;
        }
        if(cnt1>cnt0){
        if(cnt1<(n/2))solve(n,ans,temp+'(',i+1,cnt1+1,cnt0);
        solve(n,ans,temp+')',i+1,cnt1,cnt0+1);
        return;}
        else if(cnt1==cnt0){
            solve(n,ans,temp+'(',i+1,cnt1+1,cnt0);return;
        }
        return;
    }
   vector<string> AllParenthesis(int n) 
   {
     vector<string>ans;
     
     if(n==1){
         ans.push_back("()");
         return ans;
     }
     solve(2*n,ans,"",0,0,0);
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
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 
  // } Driver Code Ends