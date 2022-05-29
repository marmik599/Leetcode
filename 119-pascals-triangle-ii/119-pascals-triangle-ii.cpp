class Solution {
public:
    vector<int> getRow(int rowIndex) 
    {
        vector<int> result;
        if(rowIndex==0)    
        {
            result.push_back(1);
            return result;
        }
        if(rowIndex==1)
        {
            result.push_back(1);
            result.push_back(1);
            return result;
        }
        long long int res=1;
        for(int i=0;i<=rowIndex;i++)
        {
            if(i==0 || i==rowIndex)
                result.push_back(1);
            
            
            
            else
            {   
                res=res*(rowIndex-(i-1));
                res=res/(i);
                result.push_back(res);
            }
        }
        return result;
        
    }
};