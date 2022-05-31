class Solution {
public:
    bool hasAllCodes(string s, int k) 
    {
       if(s.size()<k)
           return false;
        
        unordered_set<string> se;
        
        for(int i=0;i<s.size()-k+1;i++)
        {
            se.insert(s.substr(i,k));
        }
        
        return (se.size()==pow(2,k));
    }
};