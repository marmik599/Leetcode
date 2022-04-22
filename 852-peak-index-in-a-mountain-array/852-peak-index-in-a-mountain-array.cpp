class Solution {
public:
    int peakIndexInMountainArray(vector<int>& nums) 
    {
        int start=0;
        int end=nums.size()-1;
        
        if(nums[0]<nums[1] && nums[2]<nums[1])
            return 1;
        
        if(nums[nums.size()-3]<nums[nums.size()-2] && nums[nums.size()-1]<nums[nums.size()-2])
            return nums.size()-2;
        
        while(start<=end)
        {
            int mid=start + (end-start)/2;
            if(nums[mid-1]<nums[mid] && nums[mid+1]<nums[mid])
                return mid;
            
            if(nums[mid-1]<nums[mid])
            {
                start=mid+1;
            }
            
            if(nums[mid-1]>nums[mid])
            {
                end=mid-1;
            }
        }
        return -1;
        
    }
};