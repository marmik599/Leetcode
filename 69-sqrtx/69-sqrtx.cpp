class Solution {
public:
    int mySqrt(int x) 
    {
        long long int start=1;
        long long int end=x;
        if(x==0 || x==1)
            return x;
        while(start<=end)
        {
            long long int mid= start + (end-start)/2;
            if(mid*mid==x)
            {
                return mid;
            }
            
            if(mid*mid<x && (mid+1)*(mid+1)>x)
            {
                return mid;
            }
            
            if(mid*mid > x)
            {
                end=mid-1;
            }
        
            if(mid*mid<x)
            {
                start=mid+1;
            }
        }
        return -1;
        
    }
};