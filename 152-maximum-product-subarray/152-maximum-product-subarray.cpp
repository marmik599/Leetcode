class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        if(nums.empty())
            return 0;
        int maxprod=1;
        int minprod=1;
        int ans=INT_MIN;
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<0)
                swap(maxprod,minprod);
            
            maxprod=max(maxprod*nums[i],nums[i]);
            minprod=min(minprod*nums[i],nums[i]);
            ans=max(maxprod,ans);
        }
        return ans;
    }
};