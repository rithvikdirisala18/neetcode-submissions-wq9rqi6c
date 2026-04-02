class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> nextInd;
        int l = 0;
        int res = 0;
        for(int i = 0; i<s.size(); i++){
            char c = s[i];
            if(nextInd.count(c)){
                l = max(nextInd[c], l);
            }
            nextInd[c] = i+1;
            res = max(res, i-l+1);
        }
        return res;
    }
};
