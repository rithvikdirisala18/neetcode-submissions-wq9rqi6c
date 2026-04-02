class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        priority_queue<pair<int, int>> pq;
        for(int i = 0; i<position.size(); i++){
            pq.push({position[i], speed[i]});
        }
        stack<pair<int, int>> st;
        while(!pq.empty()){
            if(st.empty()){
                st.push(pq.top());
                pq.pop();
                continue;
            }
            bool fleet = ((static_cast<double>(target-st.top().first)/static_cast<double>(st.top().second)) >= (static_cast<double>(target-pq.top().first)/static_cast<double>(pq.top().second)));
            if(!fleet){
                st.push(pq.top());
            }
            pq.pop();
        }
        return st.size();
    }
};
