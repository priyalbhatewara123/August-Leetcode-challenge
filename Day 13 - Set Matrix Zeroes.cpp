/*
Solution 1
Time Complexity - O(m*n)
Space Complexity - O(m+n)
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        unordered_set <int> rows; //rows to be made zero
        unordered_set <int> cols; //cols to be made zero

        //traversing the matrix for getting index of all 0 present in the matrix
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (matrix[i][j] == 0)
                {
                    rows.insert(i);
                    cols.insert(j);
                }

            }
        }

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (rows.count(i) || cols.count(j))
                    matrix[i][j] = 0;
            }
        }

    }
};

/*
Solution 2: Space Optimised
Time Complexity - O(m*n)
Space Complexity - O(1)
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();

        //for first column
        bool isCol = false;
        for (int row = 0; row < r; row++)
            if (matrix[row][0] == 0)
                isCol = true;

        for (int i = 0; i < r; i++) {
            for (int j = 1; j < c; j++) {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }

            }
        }

        for (int i = 1; i < r; i++) {
            for (int j = 1; j < c; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
            }
        }

        if (matrix[0][0] == 0) {
            for (int col = 0; col < c; col++)
                matrix[0][col] = 0;
        }
        if (isCol) {
            for (int row = 0; row < r; row++)
                matrix[row][0] = 0;
        }
    }
};

/*
Key points for solution 2:
1. Suppose first element of every row and every col is representative for that row or col.
2. If a row contains 0 then we make first element of that row as 0 and we do same for every column.
3. Since representative of first row and first col is same there we take extra variable to be representative
of first col and let matrix[0][0] be representative of first row.
4. Then we traverse matrix again and if matrix[r][0] is 0 then we make entire row 0 (same for col)
5. Make sure you make first row and col 0(if you have to) at the end.
*/