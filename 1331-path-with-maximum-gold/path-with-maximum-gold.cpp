#include <algorithm> // for max function
#include <vector>

using namespace std;

class Solution {
public:
    int rows;
    int cols;

    int dfs(int row, int col, vector<vector<int>>& grid) {
        // base case: if grid[row][col] == 0, or out of bounds, or visited
        if (row < 0 || row >= rows || col < 0 || col >= cols ||
            grid[row][col] == 0) {
            return 0;
        }

        int maxCoin = grid[row][col];
        grid[row][col] = 0;
        int upsum = dfs(row - 1, col, grid);
        int downSum = dfs(row + 1, col, grid);
        int leftsum = dfs(row, col - 1, grid);
        int rightSum = dfs(row, col + 1, grid);
         grid[row][col] =maxCoin;
        return maxCoin + max(upsum, max(downSum, max(leftsum, rightSum)));
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        int maxGold = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                maxGold = max(maxGold, dfs(i, j, grid));
               
            }
        }
        return maxGold;
    }
};
