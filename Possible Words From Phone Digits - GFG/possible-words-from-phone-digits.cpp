// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to find list of all words possible by pressing given numbers.
    vector<string> possibleWords(int a[], int N)
    {
        vector<string> ans;
        if(N==0)
            return ans;
        string output;
        string mapping[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        int index=0;
        solve(ans,mapping,output,a,index,N);
        return ans;
    }
    void solve(vector<string>& ans,string mapping[],string output,int a[],int index,int N)
    {
        if(index==N)
        {
            ans.push_back(output);
            return ;
        }
        int number=a[index];
        for(int i=0;i<mapping[number].length();i++)
        {
            output.push_back(mapping[number][i]);
            solve(ans,mapping,output,a,index+1,N);
            output.pop_back();
        }
    }
    
};


// { Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}  // } Driver Code Ends