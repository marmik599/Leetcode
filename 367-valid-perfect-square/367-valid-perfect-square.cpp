class Solution {
public:
    bool isPerfectSquare(int num) 
    {
        if(num==1 || num==0)
            return true;
        long long int start=2;
        long long int end=num;
        
        while(start<=end)
        {
            long long int mid= start+ (end-start)/2;
            if(mid*mid==num)
            {
                return true;
            }
            else if(mid*mid>num)
            {
                end=mid-1;
            }
            else if(mid*mid < num)
            {
                start=mid+1;
            }
        }
        return false;
    }
};