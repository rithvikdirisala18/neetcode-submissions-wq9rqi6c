class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        row = [[False for _ in range(9)] for _ in range(9)]
        col = [[False for _ in range(9)] for _ in range(9)]
        box = [[False for _ in range(9)] for _ in range(9)]
        for i in range(9):
            for j in range(9):
                if board[i][j]==".":
                    continue
                boxInd = (3*(i//3))+(j//3)
                num = ord(board[i][j])-ord("1")
                if row[i][num] or col[j][num] or box[boxInd][num]:
                    return False
                row[i][num] = True
                col[j][num] = True
                box[boxInd][num] = True

        return True