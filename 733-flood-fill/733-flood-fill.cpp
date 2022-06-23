class Solution {
public:
    bool isValid(vector<vector<int>>& image, int sr, int sc, int color)
    {
        if(sr>=0 && sr<image.size() && sc>=0 && sc<image[0].size())
            return true;
        return false;
    }
    void dfs(vector<vector<int>>& image, int sr, int sc, int color)
    {
        int currcolor=image[sr][sc];
        image[sr][sc]=color;
        
        
        if(isValid(image,sr-1,sc,color)==true && currcolor==image[sr-1][sc])
            dfs(image,sr-1,sc,color);
        
        if(isValid(image,sr+1,sc,color)==true && currcolor==image[sr+1][sc])
            dfs(image,sr+1,sc,color);
        
        if(isValid(image,sr,sc+1,color)==true && currcolor==image[sr][sc+1])
            dfs(image,sr,sc+1,color);
        
        if(isValid(image,sr,sc-1,color)==true && currcolor==image[sr][sc-1])
            dfs(image,sr,sc-1,color);
        return;
        

        
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
        if(image[sr][sc]==color)
            return image;
       dfs(image,sr,sc,color);
        return image;
           
    }
};