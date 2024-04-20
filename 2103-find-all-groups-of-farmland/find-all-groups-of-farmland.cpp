class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n = land.size();
        int m = land[0].size();
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (land[i][j] == 1) {
                    vector<int> arr(4);
                    // store the top left
                    arr[0] = i;
                    arr[1] = j;
                    int r = i;
                    int c = j;
                    // mark this group as visited
                    for ( r = i; r < n && land[r][j] == 1; r++) {
                        for ( c = j; c < m && land[r][c] == 1; c++) {
                            land[r][c] = 2;
                        }
                    }
                    arr[2] = r-1;
                    arr[3] = c-1 ;
                    ans.push_back(arr);
                }
            }
        }
        return ans;
    }
};