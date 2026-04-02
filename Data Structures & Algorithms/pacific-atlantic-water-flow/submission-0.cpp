class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        if(m==0) return {};
        int n = heights[0].size();
        vector<vector<bool>> pac(m, vector<bool>(n, false));
        vector<vector<bool>> atl(m, vector<bool>(n, false));

        queue<pair<int, int>> pacQ;
        queue<pair<int, int>> atlQ;
        for(int i = 0; i < m; i++){
            pacQ.push({i, 0});
            atlQ.push({i, n-1});
            pac[i][0] = true;
            atl[i][n-1] = true;
        }

        for(int i = 0; i < n; i++){
            pacQ.push({0, i});
            atlQ.push({m-1, i});
            pac[0][i] = true;
            atl[m-1][i] = true;
        }
        vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while(!pacQ.empty()){
            auto [x, y] = pacQ.front(); pacQ.pop();
            for(auto [dx, dy]: dir){
                int nx = dx+x;
                int ny = dy+y;
                if(nx<0||ny<0||nx>=heights.size()||ny>=heights[0].size()){
                    continue;
                }
                if(pac[nx][ny]==true) continue;
                if(heights[nx][ny]<heights[x][y]) continue;
                pac[nx][ny]=true;
                pacQ.push({nx, ny});
            }
        }

        vector<vector<int>> res;
        while(!atlQ.empty()){
            auto [x, y] = atlQ.front(); atlQ.pop();
            for(auto [dx, dy]: dir){
                int nx = dx+x;
                int ny = dy+y;
                if(nx<0||ny<0||nx>=heights.size()||ny>=heights[0].size()){
                    continue;
                }
                if(atl[nx][ny]==true) continue;
                if(heights[nx][ny]<heights[x][y]) continue;
                atl[nx][ny]=true;
                atlQ.push({nx, ny});
            }
        }
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(pac[i][j] && atl[i][j]) res.push_back({i, j});
            }
        }
        return res;
    }
};
