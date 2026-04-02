class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(const auto& i: nums) freq[i]++;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        for(const auto& [val, f]: freq){
            pq.push({f, val});
            if(pq.size()>k) pq.pop();
        }

        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
