class Solution {
public:
    vector<string> letterCombinations(string digits) 
    {
        string mapping[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> ans;
        if(digits.length()==0)
            return ans;
        string output;
        int index=0;
        solve(ans,mapping,output,index,digits);
        return ans;
    }
    void solve(vector<string>& ans,string mapping[],string output,int index,string digits)
    {
        if(index==digits.length())
        {
            ans.push_back(output);
            return;
        }
        
        int number=digits[index]-'0';
        
        for(int i=0;i<mapping[number].length();i++)
        {
            output.push_back(mapping[number][i]);
            solve(ans,mapping,output,index+1,digits);
            output.pop_back();
        }
    }
};