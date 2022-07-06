class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
      int m=matrix.size()-1;
        int n=matrix[0].size()-1;
        int r=0;
        int c=n;
        while(r<=m && c>=0)
        {
            if(matrix[r][c]==target)
                return true;
            else if(matrix[r][c]>target)
                c--;
            else
                r++;
        }
        return false;
    }
};