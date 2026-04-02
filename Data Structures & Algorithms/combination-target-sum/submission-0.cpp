class Solution {
public:
    void bfs(vector<vector<int>>& ans, int ind, vector<int>&nums, int t, vector<int>& curr){
        if(t==0){
            ans.push_back(curr);
            return;
        }
        if(ind>=nums.size() || t < 0){
            return;
        }
        curr.push_back(nums[ind]);
        bfs(ans, ind, nums, t-nums[ind], curr);
        curr.pop_back();
        bfs(ans, ind+1, nums, t, curr);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> curr = {};
        bfs(ans, 0, nums, target, curr);
        return ans;
    }
};
