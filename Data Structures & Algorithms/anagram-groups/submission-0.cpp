class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> ans;
        for(const auto& s: strs){
            vector<int> cnt(26, 0);
            for(const auto&c: s){
                cnt[c-'a']++;
            }

            string hash = "";
            for(int i = 0; i<26; i++){
                hash+=to_string(cnt[i])+"*";
            }
            mp[hash].push_back(s);
        }
        for(const auto&[_, s]: mp) ans.push_back(s);
        return ans;
    }
};
