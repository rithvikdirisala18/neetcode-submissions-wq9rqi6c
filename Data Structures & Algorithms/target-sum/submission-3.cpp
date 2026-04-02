class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<unordered_map<int, int>> dp(n+1);
        dp[0][0] = 1;
        
        for(int i = 0; i<nums.size(); i++){
            for(auto& prev: dp[i]){
                dp[i+1][prev.first+nums[i]]+=prev.second;
                dp[i+1][prev.first-nums[i]]+=prev.second;
            }
        }
        return dp[n][target];
    }
};
