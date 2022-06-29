class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        if(strs.size()==1)
            return strs[0];
        
        sort(strs.begin(),strs.end());
        
        string word1=strs[0];
        string word2=strs[strs.size()-1];
        
        string result;
        
        int mini=max(word1.length(),word2.length());
        
        for(int i=0;i<mini;i++)
        {
            if(word1[i]==word2[i])
                result+=word1[i];
            else
                break;
        }
        return result;
    }
};