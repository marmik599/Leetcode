// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	string fractionToDecimal(int nu, int de)
	{
	    string ans="";
	    int num=nu/de;
	    int den=nu%de;
	    ans+=to_string(num);
	    if(den==0)
	    return ans;
	    ans+=".";
	    unordered_map<int,int> mp;
	    mp.clear();
	    while(den>0)
	    {
	        if(mp.count(den))
	        {
	            ans.insert(mp[den],"(");
	            ans+=")";
	            return ans;
	        }
	        else
	        {
	            mp[den]=ans.size();
	            den=den*10;
	            num=den/de;
	            den=den%de;
	            ans+=to_string(num);
	        }
	    }
	    return ans;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int numerator, denominator;
		cin >> numerator >> denominator;
		Solution ob;
		string ans = ob.fractionToDecimal(numerator, denominator);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends