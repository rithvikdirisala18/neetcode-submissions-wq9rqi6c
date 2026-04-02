class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int s1 = text1.size();
        int s2 = text2.size();
        vector<vector<int>> dp(s1+1, vector<int>(s2+1, 0));
        for(int i = s1-1; i>=0; i--){
            for(int j = s2-1; j>=0; j--){
                if(text1[i]==text2[j]){
                    dp[i][j] = 1+dp[i+1][j+1];
                } else {
                    dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
                }
            }
        }
        return dp[0][0];
    }
};
