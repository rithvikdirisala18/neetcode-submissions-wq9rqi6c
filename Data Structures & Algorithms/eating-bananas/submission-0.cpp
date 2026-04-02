class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *max_element(piles.begin(), piles.end());
        int res = r;
        while(l<=r){
            int timeSpent = 0, mid = (l+(r-l)/2);
            for(const int& i: piles){
                timeSpent+=(i/mid)+(i%mid!=0);
            }
            if(timeSpent>h){
                l = mid+1;
            }
            else{
                res = mid;
                r = mid-1;
            }
        }
        return res;
    }
};
