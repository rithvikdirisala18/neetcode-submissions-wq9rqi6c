class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> n1 = nums1;
        vector<int> n2 = nums2;
        int tot = n1.size()+n2.size();
        int half = (tot+1)/2;
        bool odd = tot%2==1;
        if(n2.size()<n1.size()){
            swap(n1, n2);
        }
        int l = 0, r = n1.size();
        while(l<=r){
            int i = l+(r-l)/2;
            int j = half-i;

            int n1L = i>0? n1[i-1]: INT_MIN;
            int n1R = i<n1.size()?n1[i]: INT_MAX;
            int n2L = j>0? n2[j-1]: INT_MIN;
            int n2R = j<n2.size()?n2[j]: INT_MAX;

            if(n1L<=n2R && n2L<=n1R){
                if(odd){
                    return max(n1L, n2L);
                }
                else{
                    return (max(n1L, n2L)+min(n1R, n2R))/2.0;
                }
            }
            else if(n1L>n2R){
                r = i-1;
            }
            else{
                l = i+1;
            }
        }
        return 0.0;
    }
};
