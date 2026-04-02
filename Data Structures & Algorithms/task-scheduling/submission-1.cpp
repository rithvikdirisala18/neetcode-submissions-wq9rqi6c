class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26, 0);
        for(const char& c: tasks) count[c-'A']++;

        priority_queue<int> pq;
        for(const int& i: count){
            if(i>0) pq.push(i);
        }

        queue<pair<int, int>> q;
        int time = 0;
        while(!q.empty() || !pq.empty()){
            time++;
            if(pq.empty()){
                time = q.front().second;
            }
            else{
                int updateCount = pq.top()-1;
                pq.pop();
                if(updateCount>0){
                    q.push({updateCount, time+n});
                }
            }

            if(!q.empty() && q.front().second==time){
                pq.push(q.front().first);
                q.pop();
            }
        }
        return time;
    }
};
