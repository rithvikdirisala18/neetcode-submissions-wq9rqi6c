class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size()-1;
        int mA = 0;
        while(left<right){
            mA = max(mA, (right-left)*(min(heights[right], heights[left])));
            if(heights[left]>heights[right]) right--;
            else{
                left++;
            }
        }
        return mA;
    }
};
