class Solution {
public:
    int findsquare(int n)
    {
        int ans=0;
        while(n>0)
        {
            int rem=n%10;
            ans=ans + rem*rem;
            n=n/10;
        }
        return ans;
    }
    
    bool isHappy(int n) {
        
        int slow =n;
        int fast=n;
        
        do
        {
            slow=findsquare(slow);
            fast=findsquare(findsquare(fast));
        }
        while(slow!=fast);
        
        if(slow==1)
        {
            return true;
        }
        return false;
        
    }
};