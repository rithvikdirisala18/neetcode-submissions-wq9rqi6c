class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        unordered_map<int, vector<pair<int, int>>> adj;
        int n = points.size();
        for(int i = 0; i<n; i++){
            int x1 = points[i][0];
            int y1 = points[i][1];
            for(int j = i+1; j<n; j++){
                int x2 = points[j][0];
                int y2 = points[j][1];
                int dist = abs(x1-x2)+abs(y1-y2);
                adj[i].push_back({dist, j});
                adj[j].push_back({dist, i});
            }
        }

        int res = 0;
        unordered_set<int> vis;
        priority_queue<pair<int, int>> pq;
        pq.push({0, 0});
        while(vis.size()!=n){
            auto curr = pq.top(); pq.pop();
            int cost = -1*curr.first;
            int point = curr.second;
            if(vis.count(point)) continue;
            res+=cost;
            vis.insert(point);
            for(auto& nei: adj[point]){
                int neiCost = nei.first*-1;
                int neiPoint = nei.second;
                if(!vis.count(neiPoint)){
                    pq.push({neiCost, neiPoint});
                }
            }
        }
        return res;
    }
};
