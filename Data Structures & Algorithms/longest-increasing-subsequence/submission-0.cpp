class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;
        dp.push_back(nums[0]);

        int res = 1;
        for(int i = 1; i<nums.size(); i++){
            if(dp.back()<nums[i]){
                dp.push_back(nums[i]);
                res++;
                continue;
            }

            int ind = lower_bound(dp.begin(), dp.end(), nums[i]) - dp.begin();
            dp[ind] = nums[i];
        }
        return res;
    }
};
