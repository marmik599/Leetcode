class Solution {
public:
    int solve(vector<int>& nums)
    {
        int prev2=0;
        int prev1=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            int taken=nums[i];
            if(i>1)
            taken=taken+prev2;
            int nottaken=0+prev1;
            
            int curr=max(taken,nottaken);
            prev2=prev1;
            prev1=curr;
        
        }
        
        
        
        return prev1;
    }
    int rob(vector<int>& nums)
    {
        if(nums.size()==1)
            return nums[0];
        vector<int> withoutfirst,withoutlast;
        for(int i=0;i<nums.size();i++)
        {
            if(i!=0)
                withoutfirst.push_back(nums[i]);
            if(i!=nums.size()-1)
                withoutlast.push_back(nums[i]);
        }
        return max(solve(withoutfirst),solve(withoutlast));
    }
};