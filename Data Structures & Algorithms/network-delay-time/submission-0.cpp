class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_set<int> vis;
        unordered_map<int, vector<pair<int, int>>> mp;
        for(auto t: times){
            mp[t[0]].push_back({t[1], t[2]});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, k});
        int t = 0;
        while(!pq.empty()){
            auto [time, curr] = pq.top(); pq.pop();
            if(vis.count(curr)) continue;
            vis.insert(curr);
            t = time;
            for(auto [nei, ext]: mp[curr]){
                if(!vis.count(nei)){
                    pq.push({time+ext, nei});
                }
            }
        }
        return vis.size()==n? t: -1;
    }
};