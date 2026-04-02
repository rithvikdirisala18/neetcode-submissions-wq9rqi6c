class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> vis(n, false);
        queue<pair<int, int>> q;
        q.push({0, 0});
        while(!q.empty()){
            auto [ind, curr] = q.front(); q.pop();
            if(ind==n-1) return curr;
            for(int i = 1; i<=nums[ind]; i++){
                if(ind+i<n && !vis[ind+i]){
                    vis[ind+i] = true;
                    q.push({ind+i, curr+1});
                }
            }
        }
        return -1;
    }
};
