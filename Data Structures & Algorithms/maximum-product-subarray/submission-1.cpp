class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = INT_MIN;
        vector<vector<int>> segs;
        vector<int> curr;
        for(const int& n: nums){
            res = max(res, n);
            if(n==0){
                if(!curr.empty()) segs.push_back(curr);
                curr.clear();
            }
            else{
                curr.push_back(n);
            }
        }
        if(!curr.empty()) segs.push_back(curr);

        for(auto& s: segs){
            int negs = 0;
            for(auto& i: s){
                if(i<0) negs++;
            }

            int prod = 1;
            int need = (negs%2==0) ? negs: negs-1;
            negs = 0;

            for(int i = 0, j = 0; i<s.size(); i++){
                prod*=s[i];
                if(s[i]<0){
                    negs++;
                    while(negs>need){
                        prod/=s[j];
                        if(s[j]<0) negs--;
                        j++;
                    }
                }
                if(j<=i) res = max(res, prod);
            }
        }
        return res;
    }
};
