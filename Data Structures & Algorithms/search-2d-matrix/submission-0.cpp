class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(), cols = matrix[0].size();

        int up = 0, down = rows-1, mid = 0;
        while(up<=down){
            mid = up+(down-up)/2;
            if(matrix[mid][cols-1]<target){
                up = mid+1;
            }
            else if(matrix[mid][0]>target){
                down = mid-1;
            }
            else{
                break;
            }
        }

        int l = 0, r = cols-1;
        while(l<=r){
            int m = l+(r-l)/2;
            if(target>matrix[mid][m]){
                l=m+1;
            }
            else if(target<matrix[mid][m]){
                r=m-1;
            }
            else{
                return true;
            }
        }
        return false;
    }
};
