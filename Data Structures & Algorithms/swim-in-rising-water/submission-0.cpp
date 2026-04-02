class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.push({grid[0][0], 0, 0});

        int n = grid.size();
        set<pair<int, int>> vis;
        
        vis.insert({0, 0});

        while(!pq.empty()){
            auto [t, x, y] = pq.top(); pq.pop();
            if(x==n-1 && y==n-1) return t;
            for(auto [dx, dy]: dir){
                int nx = dx+x;
                int ny = dy+y;
                int setInd = (nx*n)+ny;
                if(nx>=0 && nx<n && ny>=0 && ny<n && !vis.count({nx, ny})){
                    vis.insert({nx, ny});
                    pq.push({max(grid[nx][ny], t), nx, ny});
                }
            }
        }
        return n*n;
    }
};
