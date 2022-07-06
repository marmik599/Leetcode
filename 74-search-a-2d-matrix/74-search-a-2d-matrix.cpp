class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int m=matrix.size();
        int n=matrix[0].size();
        int trow=-1;
        for(int i=0;i<m;i++)
        {
            if(target<=matrix[i][n-1])
            {
               trow=i;
                break;
            }
                
        }
        if(trow==-1)
            return false;
        cout<<trow;
        int start=0;
        int end=n-1;
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(matrix[trow][mid]==target)
                return true;
            else if(matrix[trow][mid]>target)
                end=mid-1;
            else if(matrix[trow][mid]<target)
                start=mid+1;
        }
        return false;
    }
};