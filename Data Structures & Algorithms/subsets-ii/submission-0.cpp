class Solution {
public:
    vector<vector<int>> res;

    void backtrack(int ind, vector<int> sub, vector<int>& nums){
        res.push_back(sub);
        for(int j = ind; j < nums.size(); j++){
            if(j>ind && nums[j]==nums[j-1]){
                continue;
            }
            sub.push_back(nums[j]);
            backtrack(j+1, sub, nums);
            sub.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        backtrack(0, {}, nums);
        return res;
    }
};
