class Solution {
public:
    /**
     * @param board: A list of lists of character
     * @param word: A string
     * @return: A boolean
     */
    bool exist(vector<vector<char> > &board, string word) {
        for (int r = 0; r < board.size(); r++) {
            for (int c = 0; c < board[0].size(); c++) {
                if (helper(board, word, 0, r, c)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool helper(vector<vector<char> > &board, string word, int wordPos, int r, int c) {
        if (wordPos == word.length()) {
            return true;
        }
        int rowCnt = board.size();
        int colCnt = board[0].size();
        if (r < 0 || r >= rowCnt || c < 0 || c >= colCnt) {
            return false;
        }
        if (board[r][c] != word[wordPos]) {
            return false;
        }

        char tmp = board[r][c];
        board[r][c] = 0;
        vector<pair<int, int>> DIR = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (auto d: DIR) {
            if (helper(board, word, wordPos + 1, r + d.first, c + d.second)) {
                board[r][c] = tmp;
                return true;
            }
        }
        board[r][c] = tmp;
        return false;
    }
};