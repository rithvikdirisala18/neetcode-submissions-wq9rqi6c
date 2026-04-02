class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        for(int i = 0; i<grid.size(); i++){
            for(int j = 0; j<grid[0].size(); j++){
                if(grid[i][j]==1){
                    int sz = 0;
                    queue<pair<int, int>> q;
                    grid[i][j] = 0;
                    q.push({i, j});
                    while(!q.empty()){
                        auto [x, y] = q.front();
                        sz++;
                        q.pop();
                        for(auto [dx, dy]: dir){
                            int nx = x+dx;
                            int ny = y+dy;
                            if(nx>=0 && nx<grid.size() && ny>=0 && ny<grid[0].size()&& grid[nx][ny]==1){
                                grid[nx][ny]=0;
                                q.push({nx, ny});
                            }
                        }
                    }
                    res = max(res, sz);
                }
            }
        }
        return res;
    }
};
