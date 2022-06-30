class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) 
    {
        vector<int> freq(1001,0);
        vector<int> res;
        for(int i=0;i<arr1.size();i++)
        {
            freq[arr1[i]]++;
        }
        for(auto it:arr2)
        {
            while(freq[it])
            {
                res.push_back(it);
                freq[it]--;
            }
        }
        for(int i=0;i<=1000;i++)
        {
            for(int j=0;j<freq[i];j++)
            {
                res.push_back(i);
            }
        }
        return res;
        
    }
};