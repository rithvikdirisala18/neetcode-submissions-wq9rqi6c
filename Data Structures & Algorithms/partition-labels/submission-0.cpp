class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        vector<int> lastInd(26, -1);
        for(int i = 0; i<n; i++) lastInd[s[i]-'a'] = i;
        int ind = 0;
        int end = 0;
        vector<int> ans;
        while(ind < n){
            end = max(end, lastInd[s[ind]-'a']);
            int start = ind;
            while(ind<=end){
                end = max(end, lastInd[s[ind]-'a']);
                ind++;
            }
            ans.push_back(ind-start);
        }
        return ans;
    }
};
