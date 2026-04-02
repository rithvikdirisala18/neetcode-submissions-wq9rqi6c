class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()){
            return false;
        }
        int sz = s1.size();
        string want = "";
        for(int i = 0; i<26; i++) want+="0";
        string wind = want;

        for(int i = 0; i<sz; i++){
            want[s1[i]-'a']++;
            wind[s2[i]-'a']++;
        }
        if(wind==want) return true;
        for(int i = sz; i<s2.size(); i++){
            wind[s2[i]-'a']++;
            wind[s2[i-sz]-'a']--;
            if(wind==want) return true;
        }
        return false;
    }
};
