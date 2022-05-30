class Solution {
public:
    int divide(int dividend, int divisor) 
    {
        long int dd=dividend;
        long int dv=divisor;
        
        if(dd==INT_MIN && dv==-1)
            return INT_MAX;
         if(dd==INT_MIN && dv==1)
            return INT_MIN;
        
        dd=abs(dd);
        dv=abs(dv);
        int result=0;
        while(dv<=dd)
        {
            long int mul=dv;
            int tmp=1;
            while(mul<=dd-mul)
            {
                mul+=mul;
                tmp+=tmp;
            }
            result+=tmp;
            dd=dd-mul;
        }
        
        if(dividend<0 && divisor<0 || dividend>0 && divisor>0)
            return result;
       return -result;
        
    }
};