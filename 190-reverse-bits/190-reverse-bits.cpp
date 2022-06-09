class Solution {
public:
    uint32_t reverseBits(uint32_t n)
    {
         int j=0;
        uint32_t rev=0;
        bool flag=false;
        
        for(int i=31;i>=0;i--)
        {
            uint32_t mask = (1<<i);
            if(flag)
            {
                if((n & mask) != 0)
                {
                    cout<<1;
                 uint32_t smask=(1<<j);
                 rev|=smask;
                }
                else
                {
                    cout<<0;
                }
                j++;
            }
            else
            {
              if((n & mask) != 0)
                {
                  flag=true;
                  cout<<1;
                  uint32_t smask = (1<<j);
                  rev|=smask;
                 
                } 
                else
                {
                  cout<<0;  
                }
                j++;
            }
        }
        return rev;    
    }
};