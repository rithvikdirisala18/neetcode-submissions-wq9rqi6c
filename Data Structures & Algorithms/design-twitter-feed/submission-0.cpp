class Twitter {
public:
    int time;
    unordered_map<int, unordered_set<int>> followers;
    unordered_map<int, vector<pair<int, int>>> tweets;

    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time, tweetId});
        if(tweets[userId].size()>10){
            tweets[userId].erase(tweets[userId].begin());
        }
        time--;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        followers[userId].insert(userId);
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minH;
        if(followers[userId].size()>=10){
            priority_queue<vector<int>> maxH;
            for (auto& f: followers[userId]){
                if(!tweets.count(f)) continue;
                int ind = tweets[f].size()-1;
                auto& p = tweets[f][ind];
                maxH.push({-p.first, p.second, f, ind-1});
                if(maxH.size()>10) maxH.pop();
            }
            while(!maxH.empty()){
                auto& t = maxH.top();
                maxH.pop();
                minH.push({-t[0], t[1], t[2], t[3]});
            }
        }
        else{
            for (auto& f: followers[userId]){
                if(!tweets.count(f)) continue;
                int ind = tweets[f].size()-1;
                auto& p = tweets[f][ind];
                minH.push({p.first, p.second, f, ind-1});
            }
        }
        while(!minH.empty() && res.size()<10){
            auto t = minH.top(); minH.pop();
            res.push_back(t[1]);
            int ind = t[3];
            if(ind>=0) {
                auto&p = tweets[t[2]][ind];
                minH.push({p.first, p.second, t[2], ind-1});
            }
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        followers[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(followers[followerId].count(followeeId)){
            followers[followerId].erase(followeeId);
        }
    }
};
