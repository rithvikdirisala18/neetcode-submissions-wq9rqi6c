class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        for(int i = 0; i<grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j]==0) q.push({i, j});
            }
        }

        if(q.size()==0) return;
        vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(auto[dx, dy]: dir){
                int nx = x+dx;
                int ny = y+dy;

                if(nx<0 || nx>=grid.size() || ny<0 || ny>=grid[0].size()|| grid[nx][ny]!=INT_MAX){
                    continue;
                }

                grid[nx][ny] = grid[x][y]+1;
                q.push({nx, ny});
            }
        }
    }
};
