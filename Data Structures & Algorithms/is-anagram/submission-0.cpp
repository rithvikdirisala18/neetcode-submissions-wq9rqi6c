class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        vector<int> cnt(26, 0);
        for(const char& c: s) cnt[c-'a']++;
        for(const char& c: t){
            cnt[c-'a']--;
            if(cnt[c-'a']<0) return false;
        }
        return true;
    }
};
