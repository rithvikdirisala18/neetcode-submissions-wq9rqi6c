class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDeg(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        for(auto& p: prerequisites){
            inDeg[p[1]]++;
            adj[p[0]].push_back(p[1]);
        }
        queue<int> q;
        for(int i = 0; i<numCourses; i++){
            if(inDeg[i]==0) q.push({i});
        }

        int count = 0;
        while(!q.empty()){
            int curr = q.front(); q.pop();
            count++;
            for(int n: adj[curr]){
                inDeg[n]--;
                if(inDeg[n]==0){
                    q.push(n);
                }
            }
        }
        return count == numCourses;
    }
};
