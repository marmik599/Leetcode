class Solution {
public:
    bool canArrange(vector<int>& arr, int k)
    {
            int n=arr.size();
            vector <int> freq(k,0);
            for(int i=0;i<n;i++)
            {
                int modulo=((arr[i]%k + k)%k);
                freq[modulo]+=1;
            }
        for(int i=0;i<k;i++)
        {
            cout<<freq[i]<<" ";
        }
            if(freq[0]%2!=0)
                return false;
        
            for(int i=1;i<k;i++)
            {
                
                if(freq[i]!=freq[k-i])
                    return false;
            }
        return true;
        
    }
};