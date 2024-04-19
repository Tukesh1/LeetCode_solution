class Solution {
public:
    int n = 0;
    int m =0 ;
    void dfs(vector<vector<char>>&grid,int i ,int j){
        // base case 
        if(i >= n || i<0 ||j<0||j >= m){
            return;
        }
        // water or visited 
        if(grid[i][j] == '0' || grid[i][j] == '2') return;
        grid[i][j] ='2';
        dfs(grid,i-1,j);
        dfs(grid,i+1,j);
        dfs(grid,i,j-1);
        dfs(grid,i,j+1);
    }
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int count =0 ;
        for(int i =0;i< n;i++){
            for(int j =0 ;j< m;j++){
                if(grid[i][j] == '1'){
                    dfs(grid,i,j);
                    count++;
                }
            }
        }
        return count;
    }
};