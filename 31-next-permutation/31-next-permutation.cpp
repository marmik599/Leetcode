class Solution {
public:
    void nextPermutation(vector<int>& nums) 
    {
       int n=nums.size();
        int index1=-1;
        for(int i=nums.size()-1;i>=1;i--)
        {
            if(nums[i-1]<nums[i])
            {
                index1=i-1;
                break;
            }
        }
        if(index1==-1)
        {
          reverse(nums.begin(),nums.end());
            return;
        }
            
        
        
        
        int index2=-1;
        
        
          for(int i=nums.size()-1;i>=0;i--)
            {
                if(nums[i]>nums[index1])
                {
                    index2=i;
                    break;
                }
            }  
        
        swap(nums[index2],nums[index1]);
       reverse(nums.begin()+index1+1,nums.end());
       
    }
    
    
};