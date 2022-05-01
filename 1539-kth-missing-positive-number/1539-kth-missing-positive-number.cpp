class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) 
    {
       
        int missarr=arr[arr.size()-1]-arr.size();
        
        if(k<=missarr)
        {
            int i=0;
            int j=1;
            int z=0;
            while(i<arr.size())
            {
                if(k==z)
                    return (j-1);
                if(arr[i]==j)
                {
                    i++;
                    j++;
                }
                else
                {
                    z++;
                    j++;
                }
            }
                
        }
        else
        {   
            int ans=arr[arr.size()-1];
            cout<<ans<<" ";
            k=k-missarr;
            cout<<k<<" ";
            while(k>0)
            {
                cout<<ans;
                ans=ans+1;
                k--;
            }
            return ans;
        }
        return -1;
    }
};