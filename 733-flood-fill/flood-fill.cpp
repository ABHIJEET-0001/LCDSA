class Solution {
public:
    void dfs(vector<vector<int>>& image,
             int r, int c,
             int originalColor, int color) {

        int m = image.size();
        int n = image[0].size();

       
        if (r < 0 || c < 0 || r >= m || c >= n)
            return;

        
        if (image[r][c] != originalColor)
            return;

        
        image[r][c] = color;

      
        dfs(image, r - 1, c, originalColor, color); 
        dfs(image, r + 1, c, originalColor, color); 
        dfs(image, r, c - 1, originalColor, color); 
        dfs(image, r, c + 1, originalColor, color); 
    }

    vector<vector<int>> floodFill(
        vector<vector<int>>& image,
        int sr, int sc, int color) {

        int originalColor = image[sr][sc];

       
        if (originalColor == color)
            return image;

        dfs(image, sr, sc, originalColor, color);

        return image;
    }
};