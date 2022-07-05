// { Driver Code Starts
//Initial Template for C

#include <stdio.h>


 // } Driver Code Ends
//User function Template for C


//Function to modify the matrix such that if a matrix cell matrix[i][j]
//is 1 then all the cells in its ith row and jth column will become 1.
void booleanMatrix(int r, int c, int matrix[][c])
{
    int col0=0;
    for(int i=0;i<=r-1;i++)
    {
        if(matrix[i][0]==1)
            col0=1;
            
        for(int j=0;j<=c-1;j++)
        {
            if(matrix[i][j]==1)
            {
                matrix[i][0]=1;
                matrix[0][j]=1;
            }
        }
    }
    for(int i=r-1;i>=0;i--)
    {
        for(int j=c-1;j>=1;j--)
        {
            if(matrix[i][0]==1 || matrix[0][j]==1)
                matrix[i][j]=1;
        }
        if(col0==1)
            matrix[i][0]=1;
    }
}

// { Driver Code Starts.

int main()
{
    int tc;
	scanf("%d", &tc);
	while(tc--){
		int row, col;
		scanf("%d", &row);
		scanf("%d", &col);
		int matrix[row][col];
	 
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
				scanf("%d", &matrix[i][j]);
			}
		}
		
		booleanMatrix(row, col, matrix);
		
		for(int i = 0; i < row; i++) {
		    for(int j = 0; j < col; j++)
		        printf("%d ", matrix[i][j]);
		  
		    printf("\n");
		}
	}
	return 0;
}  // } Driver Code Ends