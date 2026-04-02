class Solution {
public:
    vector<vector<int>> dp;
    vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int n;
    int m;


    int dfs(int x, int y, vector<vector<int>>& matrix){
        if(dp[x][y]!=-1) return dp[x][y];
        int len = 0;
        for(auto& [dx, dy]: dir){
            int nx = x+dx, ny = y+dy;
            if(nx<0 || ny<0 || nx>=n || ny>=m || matrix[nx][ny]<=matrix[x][y]){
                continue;
            }
            len = max(len, dfs(nx, ny, matrix));
        }
        return dp[x][y] = 1+len;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        this->n = n, this->m = m;
        dp = vector<vector<int>>(n, vector<int>(m, -1));
        int res = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                res = max(res, dfs(i, j, matrix));
            }
        }
        return res;
    }
};
