class Solution {
public:
    string longestPalindrome(string s) {
        int len = 0, ind = 0, n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for(int i = n-1; i>=0; i--){
            for(int j = i; j<n; j++){
                if(s[i]==s[j] && (j-i<=2|| dp[i+1][j-1])){
                    dp[i][j] = true;
                    if(len<(j-i+1)){
                        ind = i;
                        len = j-i+1;
                    }
                }
            }
        }
        return s.substr(ind, len);
    }
};
