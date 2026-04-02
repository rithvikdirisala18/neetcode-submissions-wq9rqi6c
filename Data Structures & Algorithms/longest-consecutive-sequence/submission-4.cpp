class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int res=0;
        for(const int& n: nums){
            int length = 1;
            if(st.find(n-1)==st.end()){
                while(st.find(n+length)!=st.end()) length++;
            }
            res = max(res, length);
        }
        return res;
    }
};
