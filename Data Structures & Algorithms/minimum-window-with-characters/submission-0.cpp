class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty() || s.empty()) return "";
        vector<int> need(128, 0);
        int required = 0;
        for(const auto& c: t){
            if(need[c]==0) required +=1;
            need[c]++;
        }

        vector<int> wind(128, 0);
        int formed = 0;

        int minLen = INT_MAX, minL = 0;
        for(int l = 0, r = 0; r<s.size(); r++){
            char curr = s[r];
            if(need[curr]>0){
                wind[curr]++;
                if(wind[curr]==need[curr]) formed++;
            }

            while(formed==required){
                if(r-l+1<minLen){
                    minLen = r-l+1;
                    minL = l;
                }
                char d = s[l++];
                if(need[d]>0){
                    if(wind[d]==need[d]) formed--;
                    wind[d]--;
                }
            }
        }
        return minLen==INT_MAX? "" : s.substr(minL, minLen);
    }
};
