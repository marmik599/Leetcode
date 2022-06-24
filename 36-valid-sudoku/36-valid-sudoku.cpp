class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board)
    {
            unordered_set<string> s;
            
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board.size();j++)
            {
                if(board[i][j]=='.')
                    continue;
                
                int row=i;
                int col=j;
                int box=(row/3)*3 + col/3;
                string str= "row" + to_string(i) + board[i][j];
                string stc= "col" + to_string(j) + board[i][j];
                string stb= "box" + to_string(box) + board[i][j];
                
                if(s.find(str)!=s.end() || s.find(stc)!=s.end() || s.find(stb)!=s.end())
                {
                    return false;
                }
                s.insert(str);
                s.insert(stc);
                s.insert(stb);
                
            }
        }
        return true;
    }
};