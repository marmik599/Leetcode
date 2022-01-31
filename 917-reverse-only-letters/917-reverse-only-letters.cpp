class Solution {
public:
    string reverseOnlyLetters(string s) {
        
        int begin=0;
        
        int end=s.length()-1;
        
        
        while(begin<end)
        {
          if(!isalpha(s[begin]))
             {
                 begin++;
             }
          if(!isalpha(s[end]))
          {
              end--;
          }
            if(isalpha(s[begin]) && isalpha(s[end]))
            {
                swap(s[begin],s[end]);
                begin++;
                end--;
                
            }     
            
        }
        
        return s;
        
    }
};