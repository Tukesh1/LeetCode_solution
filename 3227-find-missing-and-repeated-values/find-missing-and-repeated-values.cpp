class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int size = n * n;
        vector<int> ans(2, 0);
        unordered_map<int, int> freq;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                freq[grid[i][j]]++;
            }
        }
        for (int num = 1; num <= size; num++) {
            if (freq[num] == 2)
                ans[0] = num; // Repeated number
            if (freq[num] == 0)
                ans[1] = num; // Missing number
        }

        return ans;
    }
};
/*

[9,1,7]
[8,9,2]
[3,4,6]



*/