// class Solution {
// public:
//     void markCol(vector<vector<int>>& matrix, int n, int m, int j) {
//         // set all non-zero elements as -1 in the col j:
//         for (int i = 0; i < n; i++) {
//             if (matrix[i][j] != 0) {
//                 matrix[i][j] = -1;
//             }
//         }
//     }
//     void markRow(vector<vector<int>> &matrix, int n, int m, int i) {
//     // set all non-zero elements as -1 in the row i:
//     for (int j = 0; j < m; j++) {
//         if (matrix[i][j] != 0) {
//             matrix[i][j] = -1;
//         }
//     }
// }

//     void setZeroes(vector<vector<int>>& matrix) {

//         // Set -1 for rows and cols
//         // that contains 0. Don't mark any 0 as -1:
//         int n= matrix.size();
//         int m= matrix[0].size();

//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < m; j++) {
//                 if (matrix[i][j] == 0) {
//                     markRow(matrix, n, m, i);
//                     markCol(matrix, n, m, j);
//                 }
//             }
//         }

//         // Finally, mark all -1 as 0:
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < m; j++) {
//                 if (matrix[i][j] == -1) {
//                     matrix[i][j] = 0;
//                 }
//             }
//         }

//         // return matrix;
//     }
// };

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        bool isFirstColZero = false;

        // Check if the first column needs to be zeroed out
        for (int i = 0; i < n; i++) {
            if (matrix[i][0] == 0) {
                isFirstColZero = true;
                break;
            }
        }

        // Use first row and first column as markers
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Set zeros based on markers
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Set zeros for first row if needed
        if (matrix[0][0] == 0) {
            for (int j = 0; j < m; j++) {
                matrix[0][j] = 0;
            }
        }

        // Set zeros for first column if needed
        if (isFirstColZero) {
            for (int i = 0; i < n; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};
