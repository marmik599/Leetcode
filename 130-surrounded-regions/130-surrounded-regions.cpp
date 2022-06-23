class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        //from border dfs o->y
        for(int i=0;i<m;i++){
            if(board[i][0]=='O')
                dfs(board,i,0,'Y');
            if(board[i][n-1]=='O')
                dfs(board,i,n-1,'Y');
        }
        for(int j=0;j<n;j++){
            if(board[0][j]=='O')
                dfs(board,0,j,'Y');
            if(board[m-1][j]=='O')
                dfs(board,m-1,j,'Y');
        }
        //traverse dfs o->x
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O')
                    dfs(board,i,j,'X');
            }
        }
        //traverse dfs y->o
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='Y')
                    board[i][j]='O';
            }
        }
    }
    void dfs(vector<vector<char>>& board, int x, int y, char target){
        int m=board.size();
        int n=board[0].size();
        if(x<0||x>=m||y<0||y>=n||board[x][y]=='X'||board[x][y]==target)return;
        board[x][y]=target;
        //cout<<board[x][y];
        dfs(board,x+1,y,target);
        dfs(board,x,y+1,target);
        dfs(board,x,y-1,target);
        dfs(board,x-1,y,target);
    }
};