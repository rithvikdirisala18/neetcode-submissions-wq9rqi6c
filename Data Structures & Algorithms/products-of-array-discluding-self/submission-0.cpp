class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        for(int i = 1;i<n; i++){
            dp[i] = nums[i-1]*dp[i-1];
        }

        int temp = nums[n-1];
        for(int i = n-2; i>=0; i--){
            dp[i]*=temp;
            temp*=nums[i];
        }
        return dp;
    }
};
