class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> rows(9, vector<bool>(9, false));
        vector<vector<bool>> cols(9, vector<bool>(9, false));
        vector<vector<bool>> boxs(9, vector<bool>(9, false));
        for(int i = 0; i<9; i++){
            for(int j = 0; j<9; j++){
                if(board[i][j]=='.') continue;
                int valInd = board[i][j]-'1';
                if(rows[i][valInd]||cols[j][valInd]||boxs[(i/3)*3+(j/3)][valInd]){
                    return false;
                }
                rows[i][valInd] = true;
                cols[j][valInd] = true;
                boxs[(i/3)*3+(j/3)][valInd] = true;
            }
        }
        return true;
    }
};
