// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    //Complete this function
    
    vector<string> permutation(string S)
    {
       vector<string> ans;
       permute(S,ans,0);
       sort(ans.begin(),ans.end());
       return ans;
    }
    void permute(string S,vector<string> &ans,int i)
    {
        if(i==S.size())
            ans.push_back(S);
            
        for(int j=i;j<S.size();j++)
        {
            swap(S[i],S[j]);
            permute(S,ans,i+1);
            
        }
    }
    
};

// { Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}  // } Driver Code Ends