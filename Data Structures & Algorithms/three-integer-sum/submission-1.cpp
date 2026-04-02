class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i = 0; i<nums.size(); i++){
            int n = nums[i];
            if(n>0) break;
            if(i>0 && nums[i]==nums[i-1]) continue;
            int l = i+1, r = nums.size()-1;
            while(l<r){
                if(nums[l]+nums[r]+n<0){
                    l++;
                }
                else if(nums[l]+nums[r]+n>0){
                    r--;
                }
                else{
                    ans.push_back({n, nums[l], nums[r]});
                    l++;
                    r--;
                    while(l<r && nums[l]==nums[l-1]){
                        l++;
                    }
                }
            }
        }
        return ans;
    }
};
