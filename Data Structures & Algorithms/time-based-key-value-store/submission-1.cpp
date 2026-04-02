class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        vector<pair<int, string>> curr = mp[key];
        int l = 0, r = curr.size()-1;
        string res = "";
        while(l<=r){
            int mid = l+(r-l)/2;
            if(curr[mid].first==timestamp) return curr[mid].second;
            else if(curr[mid].first<timestamp){
                res = curr[mid].second;
                l = mid+1;
            }
            else{
                r = mid-1;
            }
        }
        return res;
    }
};
