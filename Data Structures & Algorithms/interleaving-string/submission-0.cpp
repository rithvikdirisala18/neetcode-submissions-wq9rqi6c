class Solution {
public:
    vector<vector<int>> mp;

    bool dp(int ind1, int ind2, string s1, string s2, string s3){
        int combInd = ind1+ind2;
        if(ind1==s1.size()&&ind2==s2.size()){
            return true;
        }

        if(mp[ind1][ind2]!=-1){
            return mp[ind1][ind2];
        }

        bool res = false;
        if(ind1<s1.size() && s1[ind1]==s3[combInd]){
            res = dp(ind1+1, ind2, s1, s2, s3);
        }

        if(ind2<s2.size() && s2[ind2]==s3[combInd]){
            res = dp(ind1, ind2+1, s1, s2, s3);
        }
        mp[ind1][ind2] = res;
        return res;
    }

    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
        int m = s2.size();
        if(m+n!=s3.size()) return false;
        mp = vector<vector<int>>(n+1, vector<int>(m+1, -1));
        return dp(0, 0, s1, s2, s3);
    }
};

