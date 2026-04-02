class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> st;
        for(const int& i: nums){
            if(st.find(i)!=st.end()) return true;
            st.insert(i);
        }
        return false;
    }
};