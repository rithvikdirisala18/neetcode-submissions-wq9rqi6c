class Solution {
public:
    int helper(int start, int end, vector<int>& nums){
        if(start==end) return nums[start];
        vector<int> dp(end-start+1, 0);
        dp[start] = nums[start];
        dp[start+1] = max(nums[start], nums[start+1]);
        for(int i = start+2; i <= end; i++){
            dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
        }
        return dp[end];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        int first = helper(0, n-2, nums);
        int second = helper(1, n-1, nums);
        return max(first, second);
    }
};
