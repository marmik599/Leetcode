class Solution {
public:
    int searchInsert(vector<int>& nums, int target) 
    {
        int start=0;
        int end=nums.size()-1;
        if(target>nums[nums.size()-1])
        {
            return nums.size();
        }
        if(target<nums[start])
        {
            return 0;
        }
        while(start<=end)
        {
            int mid=start + (end-start)/2;
            
            if(target==nums[mid])
            {
                return mid;
            }
            if(target > nums[mid] && target < nums[mid+1])
            {
                return mid+1;
            }
            if(target <nums[mid] && target>nums[mid-1])
            {
                return mid;
            }
            
            if(target>nums[mid])
            {
                start=mid+1;
            }
            else if(target<nums[mid])
            {
                end=mid-1;
            }
        }
        
        return -1;
    }
};