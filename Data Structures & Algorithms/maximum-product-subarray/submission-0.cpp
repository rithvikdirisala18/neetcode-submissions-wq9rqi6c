class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = INT_MIN;
        for(int i = 0; i<nums.size(); i++){
            int curr = nums[i];
            res = max(res, curr);
            for(int j = i+1; j<nums.size(); j++){
                curr*=nums[j];
                res = max(res, curr);
            }
        }
        return res;
    }
};
