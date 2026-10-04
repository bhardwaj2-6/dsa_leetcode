class Solution {
public:
    int n, m;

    int row[4] = {1, -1, 0, 0};
    int col[4] = {0, 0, 1, -1};

    bool valid(int a, int b, int n, int m) {
        return a >= 0 && b >= 0 && a < n && b < m;
    }

    void dfs(vector<vector<char>>& board,
             vector<vector<bool>>& visit,
             int i, int j,
             vector<pair<int,int>>& arr,
             int& flag) {

        visit[i][j] = 1;
        arr.push_back({i, j});

        // If current cell is boundary, this region cannot be surrounded
        if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
            flag = 1;
        }

        for (int k = 0; k < 4; k++) {
            int ni = i + row[k];
            int nj = j + col[k];

            if (valid(ni, nj, n, m) &&
                !visit[ni][nj] &&
                board[ni][nj] == 'O') {

                dfs(board, visit, ni, nj, arr, flag);
            }
        }
    }

    void solve(vector<vector<char>>& board) {

        n = board.size();
        m = board[0].size();

        vector<vector<bool>> visit(n, vector<bool>(m, false));

        vector<vector<pair<int,int>>> temp;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (board[i][j] == 'O' &&
                    !visit[i][j]) {

                    vector<pair<int,int>> arr;
                    int flag = 0;

                    dfs(board, visit, i, j, arr, flag);

                    if (flag == 0) {
                        temp.push_back(arr);
                    }
                }
            }
        }

        // Convert completely surrounded regions
        for (auto& region : temp) {
            for (auto& cell : region) {
                board[cell.first][cell.second] = 'X';
            }
        }
    }
};