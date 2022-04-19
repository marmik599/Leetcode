class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) 
    {
       for(int i=0;i<nums.size();i++)
       {
           int k=nums[i];
           if(k<0)
           {
               k=k*-1;
           }
           if(nums[k-1]>0)
           {
               nums[k-1]=nums[k-1]*-1;
           }
       }
        vector<int> ans;
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>0)
                ans.push_back(i+1);
            
        }
        return ans;
        
        
        
    }
};