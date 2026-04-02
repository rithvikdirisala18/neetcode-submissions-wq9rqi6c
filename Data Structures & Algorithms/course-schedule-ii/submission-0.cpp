class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indeg(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        for(auto&p: prerequisites){
            indeg[p[0]]++;
            adj[p[1]].push_back(p[0]);
        }
        queue<int> q;
        for(int i = 0; i<numCourses; i++){
            if(indeg[i]==0) q.push({i});
        }
        vector<int> ans;
        while(!q.empty()){
            int curr = q.front();q.pop();
            ans.push_back(curr);
            for(auto&n: adj[curr]){
                indeg[n]--;
                if(indeg[n]==0){
                    q.push(n);
                }
            }
        }
        return ans.size()==numCourses? ans: vector<int>();
    }
};
