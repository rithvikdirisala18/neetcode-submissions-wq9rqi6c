class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int need = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j]==2){
                    q.push({i, j});
                }
                if(grid[i][j]==1){
                    need++;
                }
            }
        }
        vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int lev = 0;
        while(need > 0 && !q.empty()){
            int sz = q.size();
            lev++;
            for(int i = 0; i<sz; i++){
                auto [x, y] = q.front(); q.pop();
                for(auto [dx, dy]: dir){
                    int nx = x+dx, ny = y+dy;
                    if(nx>=0 && nx<grid.size() && ny>=0 && ny<grid[0].size() && grid[nx][ny]==1){
                        q.push({nx, ny});
                        grid[nx][ny] = 2;
                        need--;
                    }
                }
            }
        }
        return need==0? lev : -1;
    }
};
