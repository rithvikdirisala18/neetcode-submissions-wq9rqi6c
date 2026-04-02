class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()>n-1) return false;
        vector<vector<int>> adj(n);
        for(auto& e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        unordered_set<int> vis;
        queue<pair<int, int>> q;
        q.push({0, -1});
        vis.insert(0);
        while(!q.empty()){
            auto [curr, par] = q.front();q.pop();
            for(int i: adj[curr]){
                if(i==par) continue;
                if(vis.count(i)) return false;
                q.push({i, curr});
                vis.insert(i);
            }
        }
        return vis.size()==n;
    }
};
