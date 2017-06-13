class Solution {
public:
    /**
     * @param matrix: a matrix of 0 and 1
     * @return: an integer
     */
    int maxSquare(vector<vector<int> > &matrix) {
        // write your code here
        int rowCnt = matrix.size();
        int colCnt = matrix[0].size();
        vector<vector<int> > sol(rowCnt, vector<int>(colCnt, 0));
        // sol[i][j] is the maximal square width which bottom-right cell is (i, j)
        int maxWidth = 0;
        for (size_t r = 0; r < rowCnt; r++) {
            for (size_t c = 0; c < colCnt; c++) {
                if (r == 0 || c == 0) {
                    sol[r][c] = matrix[r][c];
                } else if (matrix[r][c] == 0) {
                    sol[r][c] = 0;
                } else {
                    sol[r][c] = min(min(sol[r-1][c-1], sol[r-1][c]), sol[r][c-1]) + 1;
                }
                maxWidth = max(maxWidth, sol[r][c]);
            }
        }

        return maxWidth * maxWidth;
    }
};