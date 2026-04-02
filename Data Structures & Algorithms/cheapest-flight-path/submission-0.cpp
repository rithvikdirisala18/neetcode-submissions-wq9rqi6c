class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> it(n);
        vector<int> prices(n, INT_MAX);
        prices[src] = 0;
        for(auto& f: flights){
            it[f[0]].push_back({f[1], f[2]});
        }
        queue<tuple<int, int, int>> q;
        q.push({0, src, 0});

        while(!q.empty()){
            auto [cst, node, stops] = q.front(); q.pop();
            if(stops>k) continue;

            for(const auto& [nei, w]: it[node]){
                int nextCost = cst+w;
                if(nextCost< prices[nei]){
                    prices[nei] = nextCost;
                    q.push({nextCost, nei, stops+1});
                }
            }
        }
        return prices[dst]==INT_MAX? -1: prices[dst];
    }
};
