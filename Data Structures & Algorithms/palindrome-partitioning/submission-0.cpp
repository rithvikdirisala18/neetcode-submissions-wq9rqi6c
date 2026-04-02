class Solution {
public:
    vector<vector<bool>> dp;
    vector<vector<string>> partition(string s){
        int n = s.size();
        dp.resize(n, vector<bool>(n));
        for(int i = 1; i<=n; i++){
            for(int j = 0; j<=n-i; j++){
                dp[j][j+i-1] = (s[j]==s[j+i-1] && (j+1>(j+i-2) || dp[j+1][j+i-2]));
            }
        }
        vector<vector<string>> res;
        vector<string> part;
        helper(0, s, part, res);
        return res;
    }

    void helper(int i, string& s, vector<string>& part, vector<vector<string>>& res) {
        if(i>=s.size()){
            res.push_back(part);
            return;
        }
        for(int j = i; j < s.size(); j++){
            if(dp[i][j]){
                part.push_back(s.substr(i, j-i+1));
                helper(j+1, s, part, res);
                part.pop_back();
            }
        }
    }
};
