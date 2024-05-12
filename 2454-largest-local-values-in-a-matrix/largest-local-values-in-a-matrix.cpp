class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n=grid.size();
        int m= grid[0].size();
        vector<vector<int>>rowMax(n);
        for(int i =0;i< n;i++){
            for(int j=0 ;j<(m-2);j++){
              int currMax= max(grid[i][j],max(grid[i][j+1] , grid[i][j+2]));
              rowMax[i].push_back(currMax);
            }
        }

        // for max in col 
        vector<vector<int>>maxGrid(n-2, vector<int>(n-2 ,0));
        for(int i =0;i<(n-2);i++){
            for(int j=0 ;j<(m-2);j++){
                int currMax= max(rowMax[i][j],max(rowMax[i+1][j] , rowMax[i+2][j]));
              maxGrid[i][j]= currMax;
            }
        }
        return maxGrid;
    }
};