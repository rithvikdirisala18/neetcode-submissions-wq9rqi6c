class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        int currMin = 1, currMax = 1;
        for(const int& n: nums){
            int temp = n*currMax;
            currMax = max(max(temp, n*currMin), n);
            currMin = min(min(temp, n*currMin), n);
            res = max(res, currMax);
        }
        return res; 
    }
};
