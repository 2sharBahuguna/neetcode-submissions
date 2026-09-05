class Solution {
private:
    bool solve(int index, int row, int col, string word, vector<vector<char>>& board, int n, int m) {
        if (index == word.size()) {
            return true;
        }

        if (row < 0 || col < 0 || row >= n || col >= m || board[row][col] != word[index]) {
            return false;
        }

        char temp = board[row][col];
        board[row][col] = '#'; // Mark as visited

        int r[] = {-1, 0, +1, 0};
        int c[] = {0, +1, 0, -1};

        for (int i = 0; i < 4; i++) {
            int newR = row + r[i];
            int newC = col + c[i];

            if (solve(index + 1, newR, newC, word, board, n, m)) {
                return true;
            }
        }

        board[row][col] = temp; // Unmark visited
        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (board[row][col] == word[0]) {
                    if (solve(0, row, col, word, board, n, m)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
