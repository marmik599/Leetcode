class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        if(nums2.size()==0)
            return;
        vector<int> n1;
        for(int i=0;i<m;i++)
            n1.push_back(nums1[i]);
        
        int j=0;
        int k=0;
        
        nums1.clear();
        
        while(j<m && k<n)
        {
          if(n1[j]<=nums2[k])
          {
              nums1.push_back(n1[j]);
              j++;
          }
            else
            {
                nums1.push_back(nums2[k]);
                k++;
            }
        }
        if(j==m)
        {
            for(int i=k;i<n;i++)
            {
                nums1.push_back(nums2[i]);
            }
        }
        if(k==n)
        {
            for(int i=j;i<m;i++)
            {
                nums1.push_back(n1[i]);
            }
        }
    }
};