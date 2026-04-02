class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int num = 0;
        vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j]=='1'){
                    num++;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    while(!q.empty()){
                        auto [x, y] = q.front(); q.pop();
                        for(auto [nx, ny]: dir){
                            int dx = x+nx;
                            int dy = y+ny;
                            if(dx>=0 && dx < grid.size() && dy>=0 && dy<grid[0].size() && grid[dx][dy]=='1'){
                                grid[dx][dy] = '0';
                                q.push({dx, dy});
                            }
                        }
                    }
                }
            }
        }
        return num;
    }
};
