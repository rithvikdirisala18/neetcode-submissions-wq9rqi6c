class Solution {
public:
    void bfs(vector<vector<int>>& res, vector<int>& curr, int ind, vector<int>& nums){
        if(ind>=nums.size()){
            res.push_back(curr);
            return;
        }
        curr.push_back(nums[ind]);
        bfs(res, curr, ind+1, nums);
        curr.pop_back();
        bfs(res, curr, ind+1, nums);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr = {};
        bfs(ans, curr, 0, nums);
        return ans;
    }
};
