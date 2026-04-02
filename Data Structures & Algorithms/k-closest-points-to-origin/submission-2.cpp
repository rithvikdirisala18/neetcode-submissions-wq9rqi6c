class Solution {
public:
    double dist(vector<int> v){
        return sqrt(static_cast<double>(v[0]*v[0]) + static_cast<double>(v[1]*v[1]));
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double, vector<int>>> pq;
        for(auto &i: points){
            pq.push({dist(i), i});
            if(pq.size()>k){
                cout<<pq.top().first<< endl;
                pq.pop();
            }
        }

        vector<vector<int>> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
