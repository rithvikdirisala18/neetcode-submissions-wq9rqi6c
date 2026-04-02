class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int c = coins.size();
        sort(coins.begin(), coins.end());
        vector<vector<int>> dp(c+1, vector<int>(amount+1, 0));
        for(int i = 0; i<=c; i++){
            dp[i][0] = 1;
        }
        for(int i = c-1; i>=0; i--){
            for(int j = 0; j<=amount; j++){
                if(j>=coins[i]){
                    dp[i][j] = dp[i+1][j];
                    dp[i][j] += dp[i][j-coins[i]];
                }
            }
        }
        return dp[0][amount];
    }
};
