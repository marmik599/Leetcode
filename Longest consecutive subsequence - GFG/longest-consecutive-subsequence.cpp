// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int nums[], int n)
    {
     
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]=1;
        }
        
        for(int i=0;i<n;i++)
        {
            
                if(mp.find(nums[i]-1)!=mp.end())
                {
                    mp[nums[i]]=0;
                }
            
                
        }
        int mlength=0;
        for(int i=0;i<n;i++)
        {
            int length=0;
            if(mp[nums[i]]==1)
            {
                length++;
                while(mp.find(nums[i]+length)!=mp.end())
                {
                    length++;
                }
                mlength=max(mlength,length);
            }
            
        }
        return mlength; 
    }
};

// { Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}  // } Driver Code Ends