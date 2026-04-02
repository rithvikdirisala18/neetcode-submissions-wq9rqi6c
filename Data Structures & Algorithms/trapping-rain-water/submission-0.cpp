class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size()-1;
        int lH = height[l], rH = height[r];
        int res = 0;
        while(l<r){
            if(lH<rH){
                l++;
                lH = max(lH, height[l]);
                res+= lH-height[l];
            }
            else{
                r--;
                rH = max(rH, height[r]);
                res+= rH-height[r];
            }
        }
        return res;
    }
};
