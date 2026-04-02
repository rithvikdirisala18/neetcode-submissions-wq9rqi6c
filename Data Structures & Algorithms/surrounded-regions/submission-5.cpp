class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        queue<pair<int, int>> q;
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if((i==0 || i==m-1 || j==0 || j==n-1)&&board[i][j]=='O'){
                    q.push({i, j});
                }
            }
        }
        vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        while(!q.empty()){
            auto [x, y] = q.front();
            q.pop();
            if(board[x][y]=='O'){
                board[x][y] = 'T';
                for(auto [dx, dy]: dir){
                    int nx = x+dx;
                    int ny = y+dy;
                    if(nx>=0 && nx<m && ny>=0 && ny<n){
                        q.push({nx, ny});
                    }
                }
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j< n; j++){
                if(board[i][j]=='O'){
                    board[i][j] = 'X';
                }
                else if(board[i][j]=='T'){
                    board[i][j] = 'O';
                }
            }
        }
    }
};
