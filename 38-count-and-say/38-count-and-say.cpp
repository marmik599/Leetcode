class Solution {
public:
    
    string countAndSay(int n) 
    {
        if(n==1)
            return "1";
        if(n==2)
            return "11";
        string res="11";
        int len=n-2;
        int count;
        while(len--)
        {
         int count=1;
            string temp="";
            for(int i=1;i<res.size();i++)
            {
                if(res[i]==res[i-1])
                {
                    count++;
                }
                else
                {
                    temp+=to_string(count)+res[i-1];
                    count=1;
                }
                if(i==res.size()-1)
                {
                    temp+=to_string(count)+res[i];
                }
                
            }
            res=temp;
        }
        return res;
    }
};