class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> cnt(26, 0);
        for(auto& c: tasks) cnt[c-'A']++;

        priority_queue<int> pq;
        for(const int&i: cnt){
            if(i>0)pq.push(i);
        }

        int time = 0;
        queue<pair<int, int>> q;
        while(!pq.empty() || !q.empty()){
            time++;
            if(pq.empty()){
                time = q.front().second;
            }
            else{
                int curr = pq.top()-1;
                pq.pop();
                if(curr > 0){
                    q.push({curr, time+n});
                }
            }

            if(!q.empty() && q.front().second==time){
                pq.push({q.front().first});
                q.pop();
            }
        }
        return time;
    }
};
